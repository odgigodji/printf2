#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

//char *ft_str_toupper(char *s)
//{
//	char *t = (char *)malloc(sizeof(char) + 1);
//	int i= 0;
//
//	while(*s)
//		t[i++] = (char)ft_toupper(*s++);
//	t[i] = '\0';
//	return (t);
//}

size_t	ft_strlen_type(const char *s)
{
	unsigned long len;

	len = 0;
	while (s[len])
	{
		if (!(ft_strchr("dcsuxiXp%", s[len])))
			len++;
		else
			return (size_t)(len + 1);
	}
	return (0);
}

char ft_flag_parser(char **str, int *res)
{
	//- 0
	char flag;

//	printf("%s",*str);
	flag = ' ';
	while ((**str == '0' || **str == '-'))
	{
//		printf("%c", **str);
		if (**str == '0' && flag != '-')
		{
			flag = '0';
			//			printf("[null]");
		}
		if (**str == '-')
		{
			flag = '-';
			//			printf("[minus]");
		}
		(*str)++;
		(*res)++;
	}
//	*res = 42;
//	*spec = 42;
//	*str = *str + 1;
	return (flag);
}

int ft_width_parser(char **str, va_list ap, int *res, char *flag)
{
	int width;
//	printf("|%s|\n",*str);

	width = 0;
	if (ft_isdigit(**str) || **str == '*')
	{
		width = (**str == '*' ? va_arg(ap,int) : ft_atoi(*str));
		if (width < 0)
		{
			width *= -1;
			*flag = '-';
		}
	}
	while ((ft_isdigit(**str)) || (**str == '*'))
	{
		(*str)++;
		(*res)++;
	}
	return (width);
}

int ft_precision_parser(char **str, va_list ap, int *dot)
{
	int precision;

	precision = 0; // -1 maybe
	*dot = 0;
	if (**str == '.')
	{
		*dot = 1;
		(*str)++;
		if (ft_isdigit(**str) || **str == '*')
		{
//			printf("[pres%s]", *str);
			precision = (**str == '*' ? va_arg(ap, int) : ft_atoi(*str));
//			precision = (precision < 0) ? 0 : precision;
		}
	}
//	(*str)++;
	while ((ft_isdigit(**str)) || (**str == '*'))
	{
		(*str)++;
	}
	return (precision);
}

char *f(unsigned long x, int flag)//perevod v 16
{
//	printf("TYPEE1%c", flag);
	unsigned long tmp;
	char *c;
	int i = 1;

//	if (!x)
//		return 0;
	tmp = x;
	while (tmp >= 16)
	{
		tmp = tmp/16;
		i++;
	}
	if(!(c = (char *)malloc(i + 1)))
		return (NULL);
	c[i] = '\0';
	tmp = x;
//	char o = 'A';
	while (i > 0)
	{
		x %= 16;
		if (x >= 10)
			c[i - 1] = ((flag == 0) ? (x - 10 + 97) : (x - 10 + 65));
		else
			c[i - 1] = x + 48;
		tmp /= 16;
		x = tmp;
		i--;
	}
//	printf("%s",c);
	return (c);
}

//t_value	ft_val_init(t_value value)
//{
//	value.d = 0;//  ft_calloc(6, 1);
////	value.c = (char)malloc(sizeof(char));
//	value.c = '\0';
//	value.s = "\0";
//	value.u = 0;
//	value.x = "\0";
//	value.X = "\0";
//	value.p = "\0";
//	return(value);
////	printf("CCC:===%c\n",value.c);
//}

t_value ft_type_parser(char **str, va_list ap, char *type, int *len)
{
//	char type;
	t_value value;

	value.d = 0;//  ft_calloc(6, 1);
//	value.c = (char)malloc(sizeof(char));
	value.c = '\0';
	value.s = "\0";
	value.u = 0;
	value.x = "\0";
	value.X = "\0";
	value.p = "\0";

//	value = ft_val_init(value);

//	value.c = '$';
//	printf("CCC:===%s\n",value.x);

	if ((**str == 'd' || **str == 'i' ) && (*type = 'd'))
	{
		value.d = va_arg(ap, int);
		*len = (value.d > 0) ? ft_numlen(value.d) : ft_numlen(-1 * value.d);
	}
	if (**str == 'c' && (*type = 'c') && (*len = 1))
	{
		value.c = va_arg(ap, int); // char
	}
	if (**str == 's' && (*type = 's'))
	{
		value.s = va_arg(ap, char *);
		if (value.s == NULL)
			value.s = "(null)";
		*len = ft_strlen(value.s);
	}
	if (**str == 'u' && (*type = 'u'))
	{
//		value.u = (char*)malloc(sizeof(unsigned long) * 20);
		*len = ft_numlen_unsigned(value.u = va_arg(ap, unsigned int));
	}
	if (**str == 'x' && (*type = 'x'))
	{
		*len = ft_strlen(value.x = f(va_arg(ap, unsigned int), 0));
	}
	if (**str == 'X' && (*type = 'X'))
	{
		value.X = f(va_arg(ap, unsigned int), 1);
		*len = ft_strlen(value.X);
	}
	if (**str == 'p' && (*type = 'p'))
	{
		value.p = f(va_arg(ap, unsigned long), 0);
		*len = ft_strlen(value.p);
//
	}
	if (**str == '%' && (*type = '%'))
		*len = 1;
	(*str)++;
	return (value);
}

void ft_parser(char *str, va_list ap, t_spec *spec)
{
	int res = 0;
//	t_spec *spec;

//	if (!(spec = (t_spec *)malloc(sizeof(t_spec*))))
//		return(NULL);
	spec->width = 0;

	spec->len_after_perc = ft_strlen_type(str);
//	printf("[RES%d]",spec->len_after_perc);

	//%123.54d
//	printf("Стартовая позиция:|%s|\n",str);
	spec->flag = ft_flag_parser(&str, &res);//, &spec->size);//указатель на
	// строку

//	printf("Позиция после парсера флага:|%s|",str);
//	printf("|flag:'%c'|\n",spec ->flag);
	spec->width = ft_width_parser(&str, ap, &res, &spec->flag);
//	printf("Позиция после парсера ширины:|%s|",str);

	spec->precision = ft_precision_parser(&str, ap, &spec->dot);
//	printf ("DOT:%d\n", spec->dot);
//	printf("|width:%d|\n",spec ->width);
//	printf("Позиция после парсера точности:|%s|",str);
//	printf("|precision:%d|\n",spec ->precision);
//	char c = *str;
//	if (spec->)
//	if ((ft_strchr("dcsuxdXp%", *str)))
//		printf("KEK");
	spec->value = ft_type_parser(&str,  ap, &spec->type, &spec->len);
//	printf("Позиция после парсера типа:|%s|",str);


//	printf("|type:%c|\n",spec ->type);
//	if (spec->type == 'd')
//		printf("|type_value:%d|\n",spec ->value.d);
//	else if (spec->type == 'c')
//		printf("|type_value:%c|\n",spec ->value.c);
//	else if (spec->type == 's')
//		printf("|type_value:%s|\n",spec ->value.s);
//	else if (spec->type == 'u')
//		printf("|type_value:%u|\n",spec ->value.u);
//	else if (spec->type == 'x')
//		printf("|type_value:%s|\n",spec ->value.x);

//	printf("RES:%d",res);

//	char c = spec->type_value.char_value = '$';
//	printf("%c",c);


//	printf("\nVARG%d\n",va_arg(ap, int));


//	if (spec->dot = ft_dot_pars(&str))
//		printf("dot have :)\n");

//	va_end(ap);

	// где мы
	// остановились
//	spec -> width =

//	printf("|%s|\n",str);
//	printf("|%d|\n",spec->size);

//	return(spec);
}
