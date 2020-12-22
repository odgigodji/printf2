#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

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
}//done

char ft_flag_parser(char **str)
{
	char flag;

	flag = ' ';
	while ((**str == '0' || **str == '-'))
	{
		if (**str == '0' && flag != '-')
		{
			flag = '0';
		}
		if (**str == '-')
		{
			flag = '-';
		}
		(*str)++;
	}
	return (flag);
}//done

int ft_width_parser(char **str, va_list ap,char *flag)
{
	int width;

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
	}
	return (width);
}//done

int ft_precision_parser(char **str, va_list ap, int *dot)
{
	int precision;

	precision = 0;
	*dot = 0;
	if (**str == '.')
	{
		*dot = 1;
		(*str)++;
		if (ft_isdigit(**str) || **str == '*')
		{
			precision = (**str == '*' ? va_arg(ap, int) : ft_atoi(*str));
		}
	}
	while ((ft_isdigit(**str)) || (**str == '*'))
	{
		(*str)++;
	}
	return (precision);
}//done

char *atoi_16(unsigned long x, int flag)//done
{
	unsigned long tmp;
	char *c;

	int i = 1;
	tmp = x;
	while (tmp >= 16 && i++)
		tmp = tmp/16;
//	return (NULL); ////test
	if(!(c = (char *)malloc(i + 1)))
		return (NULL);
	c[i] = '\0';
	tmp = x;
	while (i > 0)
	{
		x %= 16;
		if (x >= 10)
			c[i - 1] = (char)((flag == 0) ? (x - 10 + 97) : (x - 10 + 65));
		else
			c[i - 1] = (char)(x + 48);
		tmp /= 16;
		x = tmp;
		i--;
	}
	return (c);
}

t_value	ft_val_init(void)
{
	t_value value;

	value.d = 0;
	value.c = '\0';
	value.s = "\0";
	value.u = 0;
	value.x = "\0";
	value.X = "\0";
	value.p = "\0";
	value.error = 0;
	return (value);
}//done

//t_value ft_type_pars_x_X_p(t_value value, va_list ap, char *type, int *len)
//{
//	t_value value;
//
////	value = ft_val_init();
//	if (**str == 'x' && (*type = 'x'))
//	{
//		*len = ft_strlen(value.x = atoi_16(va_arg(ap, unsigned int), 0));
//	}
//	if (**str == 'X' && (*type = 'X'))
//	{
//		value.X = atoi_16(va_arg(ap, unsigned int), 1);
////		value.X = NULL;
//		if (value.X == NULL)
//		{
//			value.error = -1;
//			return (value);
//		}
//		*len = ft_strlen(value.X);
//	}
//	if (**str == 'p' && (*type = 'p'))
//	{
//		value.p = atoi_16(va_arg(ap, unsigned long), 0);
//		*len = ft_strlen(value.p);
//	}
//	return (value);
//}

t_value ft_type_parser(char **str, va_list ap, char *type, int *len)
{
	t_value value;

	value = ft_val_init();
	if ((**str == 'd' || **str == 'i' ) && (*type = 'd'))
	{
//		value.d = va_arg(ap, int);
		*len = ((value.d = va_arg(ap, int)) > 0) ? ft_numlen(value.d) :
				ft_numlen(-1 * value.d);
	}
	if (**str == 'c' && (*type = 'c') && (*len = 1))
		value.c = va_arg(ap, int); // char
	if (**str == 's' && (*type = 's'))
	{
		*len = ft_strlen(value.s = \
		((value.s = va_arg(ap, char *)) == NULL) ? """(null)" :value.s);
//		if (value.s == NULL)
//			value.s = "(null)";
//		*len = ft_strlen(value.s);
	}
	if (**str == 'u' && (*type = 'u'))
		*len = ft_numlen_unsigned(value.u = va_arg(ap, unsigned int));


//	value = ft_type_pars_x_X_p(str, ap, type, len);
	if (**str == 'x' && (*type = 'x'))
	{
		*len = ft_strlen(value.x = atoi_16(va_arg(ap, unsigned int), 0));
	}
	if (**str == 'X' && (*type = 'X'))
	{
		value.X = atoi_16(va_arg(ap, unsigned int), 1);
//		value.X = NULL;
		if (value.X == NULL)
		{
			value.error = -1;
			return (value);
		}
		*len = ft_strlen(value.X);
	}
	if (**str == 'p' && (*type = 'p'))
	{
		value.p = atoi_16(va_arg(ap, unsigned long), 0);
		*len = ft_strlen(value.p);
	}
	if (**str == '%' && (*type = '%'))
		*len = 1;
	(*str)++;
	return (value);
}

void ft_parser(char *str, va_list ap, t_spec *spec)//done
{
	spec->len_after_perc = ft_strlen_type(str);
	spec->flag = ft_flag_parser(&str);
	spec->width = ft_width_parser(&str, ap, &spec->flag);
	spec->precision = ft_precision_parser(&str, ap, &spec->dot);
	spec->value = ft_type_parser(&str, ap, &spec->type, &spec->len);
//	printf("%d", spec->value.error);
	if (spec->value.error == -1)
		return ;
}
