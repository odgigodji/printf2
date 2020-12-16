#include "ft_printf.h"

void 	print_value(t_value value, char type, int precision, int len)
{
//	printf("\nVALUE IN PRINT_VALUE\nd:%d\nc:%c\ns:%s\n", value.d, value
//	.c, value.s);
//	int precision = 15;
//	int len =5;
	if (type == 'c')
		ft_putchar(value.c);
	if (type == 's')
	{
//		if (precision)
			ft_putstrn(value.s, precision);
//		else
//			ft_putstr(value.s);
	}
	if (type == 'd')
	{
		while (precision > len++)
		{
			ft_putchar('0');
		}
		ft_putnbr(value.d);
	}
	if (type == 'x')
		ft_putstr(value.x);
	if (type == 'p')
		ft_putstr(value.p);
}

void 	ft_print_d(t_spec *spec)
{
	int len;
	char c;

	if (spec->value.d < 0 && spec->dot != 1 && spec->flag != ' '\
	&& spec->precision != 0)
	{
		spec->value.d *= -1;
		ft_putchar('-');
	}
	len = spec->len;
	if (spec->flag == '-')
	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > len++)
			ft_putchar('0');
		ft_putnbr(spec->value.d);

		while (len++ < spec->width)
			ft_putchar(' ');
	}
	else
	{
		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len;
		while (len++ < spec->width)
			ft_putchar(c);
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > len++)
			ft_putchar('0');
		ft_putnbr(spec->value.d);
	}
}

void 	ft_print_s(t_spec *spec)
{
//	int hz = spec->width - spec->len + spec->precision;
	spec->precision = (spec->precision > spec->len ? spec->len : spec
			->precision);
	if (spec->flag != '-' && spec->width >= spec->precision)
	{
		while (spec->width--)
		{
//			if (spec->width < spec->len)
//				break ;
			ft_putchar((spec->flag == '0') ? '0' : ' ');
			if (spec->width == spec->precision)
				break ;
		}
	}
	if (spec->dot == 1)
		ft_putstrn(spec->value.s, spec->precision);
//	else if (spec->width < spec->len)
//		ft_putstr(spec->value.s);
	else
	{
		ft_putstr(spec->value.s);
		if (spec->flag == '-')
		{
			while (spec->width-- > spec->len)
				ft_putchar(' ');
		}
	}
}

void 	ft_print_c(t_spec *spec)
{
	if (spec->flag != '-')
	{
		while (spec->width-- > 1)
			ft_putchar((spec->flag == '0') ? '0' : ' ');
		ft_putchar((spec->type == '%')\
		? '%' : spec->value.c);
	}
	else
	{
//		ft_putchar(spec->value.c);
		ft_putchar((spec->type == '%')\
		? '%' : spec->value.c);
		while (spec->width-- > 1)
			ft_putchar(' ');
	}
}

void 	ft_print_u(t_spec *spec)
{
	int len;
	char c;

	len = spec->len;
	if (spec->flag == '-')
	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putnbr_unsigned(spec->value.u);

		while (len++ < spec->width)
			ft_putchar(' ');
	}
	else
	{
		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len;
		while (len++ < spec->width)
			ft_putchar(c);
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putnbr_unsigned(spec->value.u);
	}
}

void 	ft_print_x(t_spec *spec)
{
	int len;
	char c;

	len = spec->len;
	if (spec->flag == '-')
	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putstr(spec->value.x);

		while (len++ < spec->width)
			ft_putchar(' ');
	}
	else
	{
		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len;
		while (len++ < spec->width)
			ft_putchar(c);
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putstr(spec->value.x);
	}
}

void 	ft_print_X(t_spec *spec)
{
	int len;
	char c;

	len = spec->len;
	if (spec->flag == '-')
	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putstr(spec->value.X);

		while (len++ < spec->width)
			ft_putchar(' ');
	}
	else
	{
		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len;
		while (len++ < spec->width)
			ft_putchar(c);
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putstr(spec->value.X);
	}
}

void 	ft_print_p(t_spec *spec)
{
	int len;
	char c;

	len = spec->len;
	if (spec->flag == '-')
	{
		ft_putstr("0x");
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putstr(spec->value.p);
		while (len++ < spec->width)
			ft_putchar(' ');
	}
	else
	{
		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len-2;
		else
			spec->width = spec->width - len ;
		while (len++ < spec->width)
			ft_putchar(c);
		ft_putstr("0x");
		while (spec->precision > spec->len++)
			ft_putchar('0');
		ft_putstr(spec->value.p);
	}
}

int 	ft_lenn(t_spec *spec);

int	ft_processor(t_spec *spec)
{
//	printf("\n\n-------------This is processor mfqz!-\n");
//
//	printf("flag:'%c'\nwidth:%d\nprecision:%d\ntype:%c\nlen_value:%d\n"
//		   "dot:%d\n-----------------------------------------------\n", \
//    spec->flag, spec->width, spec->precision, spec->type, spec->len,
//		   spec->dot);
//	printf("VALUES:\nd:%d\nc:%c\nu:%u\nx:%s\nX:%s\np:%s\ns:%s\n" ,\
//	spec->value.d, spec->value.c, spec->value.u, spec->value.x, \
//	spec->value.X, spec->value.p, spec->value.s);

//	printf("\nPROC:");

	int LEN =ft_lenn(spec);
	if (spec->type == 'd')
		ft_print_d(spec);
	if (spec->type == 's')
		ft_print_s(spec);
	if (spec->type == 'c' || spec->type == '%')
		ft_print_c(spec);
	if (spec->type == 'u')
		ft_print_u(spec);
	if (spec->type == 'x')
		ft_print_x(spec);
	if (spec->type == 'p')
		ft_print_p(spec);
	if (spec->type == 'X')
		ft_print_X(spec);
	return (LEN);
//	printf("|LEN%d|",ft_lenn(spec));
//	else
//		while(spec->len_after_perc--)
//			ft_putchar(' ');
//	else
//		ft_putstr("\nPut_type\n");

//		ft_print_d(spec);
}

int 	ft_lenn(t_spec *spec)
{
	if (!spec->width && !spec->precision)
		return (spec->len);
	else if (spec->width && !spec->precision)
		return (spec->width);
	else if (!spec->width && spec->precision)
		return ((spec->type=='s' ? spec->precision :\
		spec->len));
	else if (!spec->width > spec->precision)
		return(1);
	else if (spec->width < spec->precision)
		return (2);
}

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



//	if (spec->type == 'x')
//		ft_print_x(spec);
//	if (spec->type == 'p')
//		print_value(spec->value, spec->type, spec->precision, spec->len);

//	int len = spec->len; //find len string or int
//	char c;
//
////Обработка ширины и точности
//	if (spec->flag == '0' || spec->flag == ' ')
//	{
//		if (spec->dot && spec->precision > len && spec->type == 'd') // если
//			// точность
//			// есть вообще
//			spec->width = spec->width - spec->precision + len;
////			spec->len = spec->precision;
//		while (len < spec->width)
//		{
//			c = ((spec->flag == '0' && (((spec->type != 'd' && spec->dot)) ||\
//spec->type == 'd' && !spec->dot)
// ? '0' : ' '));
// 			ft_putchar(c);
//			len++;
//		}
////		if ((spec->precision > spec->len) && spec->type == 'd')
////		{
////			while(spec->precision > spec->len++)
////			{
////				ft_putchar('0');
////			}
////		}
//		print_value(spec->value, spec->type, spec->precision, spec->len);
////		printf("%d\n",spec->value.d);
//	}
//	else
////	if (spec->flag == '-')
//	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
////		printf("%d\n",spec->value.d);
//		while (len++ < spec->width)
//		{
//			write(1, ' ', 1);
////			len++;
//		}
//	}

	// Обработка точности
//	if (spec->precision > spec->len)
//	{
//		while(spec->precision > spec->len)
//		{
//			write(1, '0', 1);
//			spec->len++;
//		}
//	}
//	print_value(spec->value, spec->type);
//write(1, '|', 1);
//}




//void 	ft_print_d1(t_spec *spec)
//{
//	int len = spec->len; //find len string or int
//	char c;
//
////Обработка ширины и точности
//	if (spec->flag == '0' || spec->flag == ' ')
//	{
//		if (spec->dot && spec->precision > len && spec->type == 'd') // если
//			// точность
//			// есть вообще
//			spec->width = spec->width - spec->precision + len;
////			spec->len = spec->precision;
//		while (len < spec->width)
//		{
//			c = ((spec->flag == '0' && (((spec->type != 'd' && spec->dot)) ||\
//spec->type == 'd' && !spec->dot)
//				  ? '0' : ' '));
//			ft_putchar(c);
//			len++;
//		}
////		if ((spec->precision > spec->len) && spec->type == 'd')
////		{
////			while(spec->precision > spec->len++)
////			{
////				ft_putchar('0');
////			}
////		}
//		print_value(spec->value, spec->type, spec->precision, spec->len);
////		printf("%d\n",spec->value.d);
//	}
//	else
////	if (spec->flag == '-')
//	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
////		printf("%d\n",spec->value.d);
//		while (len++ < spec->width)
//		{
//			write(1, ' ', 1);
////			len++;
//		}
//	}
//}

//void 	ft_print_s(t_spec *spec)
//{
////	int hz = spec->width - spec->len + spec->precision;
//	spec->precision = (spec->precision > spec->len ? spec->len : spec
//			->precision);
//	if (spec->width >= spec->len && spec->flag != '-')
//	{
//		while (spec->width--)
//		{
//			ft_putchar((spec->flag == '0') ? '0' : ' ');
//			if (spec->width == spec->precision)
//				break;
//		}
//	}
//	if (spec->dot)
//		ft_putstrn(spec->value.s, spec->precision);
//	else
//		ft_putstr(spec->value.s);
//}
