#include "ft_printf.h"

void 	print_value(t_value value, char type, int precision, int len)
{
//	printf("\nVALUE IN PRINT_VALUE\nd:%d\nc:%c\ns:%s\n", value.d, value
//	.c, value.s);
//	int precision = 15;
//	int len =5;
	if (type == 'c')
		ft_putchar1(value.c);
	if (type == 's')
	{
//		if (precision)
			ft_putstrn1(value.s, precision);
//		else
//			ft_putstr(value.s);
	}
	if (type == 'd')
	{
		while (precision > len++)
		{
			ft_putchar1('0');
		}
		ft_putnbr1(value.d);
	}
	if (type == 'x')
		ft_putstr1(value.x);
	if (type == 'p')
		ft_putstr1(value.p);
}

//если точность больше длины
void	ft_print_with_zeroes(t_spec *spec)
{
	int num_zero;

	if (spec->dot == 1 && !spec->precision && !spec->value.d && spec->width
	== -1)
		return;
	if (spec->precision == 0 && spec->dot == 1 && spec->value.d == 0)
	{
		ft_putchar1(' ');
		return;
	}
	if (spec->precision < spec->len)
		ft_putnbr1(spec->value.d);
	else
	{
		num_zero = spec->precision - spec->len;
		if (spec->value.d < 0)
		{
			ft_putchar1('-');
//			*len = *len +1;
		}
		while (num_zero--)
		{
			ft_putchar1('0');
			spec->len++;
		}
		if (spec->value.d < 0)
			ft_putnbr1(-1 * spec->value.d);
		else
			ft_putnbr1(spec->value.d);
//		printf("len v itoge:%d", *len);
//		*len = ft_strlen(s = ft_strjoin\
//		(ft_memset(t, '0', num_zero), ft_itoa(nb)));
	}

}

//void 	ft_print_d2(t_spec *spec)
//{
//
//}



void 	ft_print_d(t_spec *spec)
{
	int len;

	len = spec->len;
//	if (spec->precision < 0)
//		spec->precision = spec->len;
	if (spec->flag == '-')
	{
		if (spec->value.d < 0)
		{
//			len += 1;
			ft_putchar1('-');
		}
		while (spec->precision > len++ )
			ft_putchar1('0');

//		ft_print_with_zeroes(&spec->len, spec->value.d, spec->precision);
		if (spec->dot == 1 && !spec->precision && !spec->value.d)
		{
			if (spec->width == 0)
				return;
			ft_putchar1(' ');
		}
		else
		{
			ft_putnbr1((spec->value.d < 0) ? -1 * spec->value.d : spec->value.d);
			len = (spec->value.d < 0 ? len+1 : len);
		}
		while (len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
	{
		int hz = 0;
		if (spec->value.d < 0)
		{
			hz = (spec->precision > spec->len && spec->dot == 1) ?
					spec->precision + 1 : spec->len + 1;
//			ft_putchar('-');
		}

		else
			hz = (spec->precision > spec->len) ? spec->precision  :
					 spec->len;

		if ((spec->width && spec->flag == '0' && spec->value.d
		        <0 ) && (!spec->dot || (spec->precision < 0 && spec->dot)))


//		if ((spec->width && !spec->dot && spec->flag == '0' && spec->value.d <
//		        0 )|| (spec->flag == '0' && spec->width && spec->dot &&
//		        		spec->precision < 0 &&
//		        spec->value
//		        .d <
//		                0))

		{
			ft_putchar1('-');
			spec->value.d *= -1;
		}
		while(spec->width-- > hz ) //&& spec->dot
		{
			if (spec->dot && spec->precision >=0) // ?????
				spec->flag = ' ';
			ft_putchar1((spec->flag == '0' || (!spec->dot && spec->flag !=
			' ')) ?
			'0' : ' ');
		}
		ft_print_with_zeroes(spec);
	}
}

void	ft_print_s(t_spec *spec)
{
	int i = 0;

//	printf("[%d]", spec->precision);
//	if (spec->value.s == NULL)
//		spec->value.s = "(null)";
	if (spec->precision > 0 && spec->precision < spec->len)
		spec->len = spec->precision;
	if (spec->precision == 0 && spec->dot == 1)
		spec->len = 0 ;
	if (spec->flag == ' ')
	{
		while (i++ < (spec->width - spec->len))
			ft_putchar1(' ');
		ft_putstrn1(spec->value.s, spec->len);
	}
	else if (spec->flag == '-')
	{
		ft_putstrn1(spec->value.s, spec->len);
		while (i++ < (spec->width - spec->len))
			ft_putchar1(' ');
	}
	else if (spec->flag == '0')
	{
//		printf("[%c]",spec->flag);
//		printf("[%d]",spec->width);
		while (i++ < (spec->width - spec->len))
			ft_putchar1('0');
		ft_putstrn1(spec->value.s, spec->len);
	}
}

void 	ft_print_c(t_spec *spec)
{
	if (spec->flag != '-')
	{
		while (spec->width-- > 1)
			ft_putchar1((spec->flag == '0') ? '0' : ' ');
		ft_putchar1((spec->type == '%')\
		? '%' : spec->value.c);
	}
	else
	{
//		ft_putchar1(spec->value.c);
		ft_putchar1((spec->type == '%')\
		? '%' : spec->value.c);
		while (spec->width-- > 1)
			ft_putchar1(' ');
	}
}

void 	ft_print_u(t_spec *spec)
{
	int len;
	char c;

	if (!spec->precision && !spec->value.u && spec->dot)
	{
		while (spec->width--)
		{
			ft_putchar1(' ');
		}
		return;
	}
	len = spec->len;
	if (spec->flag == '-')
	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putnbr_unsigned1(spec->value.u);

		while (spec->len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
	{
		c = ((spec->flag == '0') && (!spec->dot || (spec->precision < 0 && \
				spec->width)) ? '0' : ' ');
//		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len;
		while (len++ < spec->width)
			ft_putchar1(c);
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putnbr_unsigned1(spec->value.u);
	}
}

void 	ft_print_x(t_spec *spec)
{
	int len;
	char c;

	if (!spec->precision && spec->value.x[0] == '0' && spec->dot)
	{
		while (spec->width--)
		{
			ft_putchar1(' ');
		}
		return;
	}
	len = spec->len;
	if (spec->flag == '-')
	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.x);

		while (spec->len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
	{
		c = ((spec->flag == '0') && (!spec->dot || (spec->precision < 0 && \
				spec->width)) ? '0' : ' ');
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len;
		while (len++ < spec->width)
			ft_putchar1(c);
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.x);
	}
//	free(spec->value.x);
}

void 	ft_print_X(t_spec *spec)
{
	int len;
	char c;

	if (!spec->precision && spec->value.X[0] == '0' && spec->dot)
	{
		while (spec->width--)
		{
			ft_putchar1(' ');
		}
		return;
	}
	len = spec->len;
	if (spec->flag == '-')
	{
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.X);

		while (spec->len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
	{
		c = ((spec->flag == '0') && (!spec->dot || (spec->precision < 0 && \
				spec->width)) ? '0' : ' ');
//		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len;
		while (len++ < spec->width)
			ft_putchar1(c);
//		print_value(spec->value, spec->type, spec->precision, spec->len);
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.X);
	}
}

int 	ft_spaces_p(t_spec *spec)
{
	int len;

	len = ft_strlen(spec->value.p) + 2;
	if (spec->width > len)
		return (spec->width - len);
	else
		return (0);
}

void 	ft_print_p(t_spec *spec) {
	//spec
	//value.p
//	printf("%s",spec->value.p);


	int len;
	char c;
	int spaces;

	if (!spec->precision && spec->value.p[0] == '0' && spec->dot)
	{

		while (spec->width-- > 2)
		{
			ft_putchar1(' ');
		}
		ft_putstr1("0x");
		return;
	}

	spaces = ft_spaces_p(spec);
//	len = spec->len;
	len = 0;
	if (spec->flag == '-')
	{
		ft_putstr1("0x");
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.p);
		while (len++ < spaces)
			ft_putchar1(' ');
	}
	else
	{
		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
		if (spec->dot && spec->precision > len)
			spec->width = spec->width - spec->precision + len-2;
		else
			spec->width = spec->width - len ;
		while (len++ < spaces)
			ft_putchar1(c);
		ft_putstr1("0x");
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.p);
	}
}

void	ft_processor(t_spec *spec)
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

	if (spec->type == 'd')
		ft_print_d(spec);
	if (spec->type == 's')
		ft_print_s(spec);
	if (spec->type == 'c' || spec->type == '%')
		ft_print_c(spec);
	if (spec->type == 'u')
		ft_print_u(spec);
	if (spec->type == 'x')
	{
		ft_print_x(spec);
		free(spec->value.x);
	}
	if (spec->type == 'p')
	{
		ft_print_p(spec);
		free(spec->value.p);
	}
	if (spec->type == 'X')
	{
		ft_print_X(spec);
		free(spec->value.X);
	}

//	printf("|LEN%d|",ft_lenn(spec));
//	else
//		while(spec->len_after_perc--)
//			ft_putchar1(' ');
//	else
//		ft_putstr("\nPut_type\n");

//		ft_print_d(spec);
}


//int 	ft_lenn(t_spec *spec)
//{
//	if (!spec->width && !spec->precision)
//		return (spec->len);
//	else if (spec->width && !spec->precision)
//		return (spec->width);
//	else if (!spec->width && spec->precision)
//		return ((spec->type=='s' ? spec->precision :\
//		spec->len));
//	else if (spec->width > spec->precision)
//		return(spec->width);
//	else if (spec->width < spec->precision)
//		return (0);
//	return 0;
//}

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
// 			ft_putchar1(c);
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
//			ft_putchar1(c);
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
//			ft_putchar1((spec->flag == '0') ? '0' : ' ');
//			if (spec->width == spec->precision)
//				break;
//		}
//	}
//	if (spec->dot)
//		ft_putstrn(spec->value.s, spec->precision);
//	else
//		ft_putstr(spec->value.s);
//}


//void 	ft_print_s1(t_spec *spec)
//{
//	//p>=0 && p<l togda vliyaet
//	//if (precision >= 0 && precision < len)
////    	len = precision
////	int hz = spec->width - spec->len + spec->precision;
//
////	if (spec->precision >= 0 && spec->precision < spec->len)
////		spec->len = spec->precision;
//
////	spec->precision = (spec->precision > spec->len ? spec->len : spec
////			->precision);
////	spec->len = (spec->precision < spec->len && spec->dot == 1) ?
////			spec->precision :
////			spec->len;
//	if (spec->flag != '-' && spec->width >= spec->precision)
//	{
//		while (spec->width--)
//		{
//			if (spec->width < spec->len)
//				break ;
//			ft_putchar1((spec->flag == '0') ? '0' : ' ');
//			if (spec->width == spec->precision)//precision
//				break ;
//		}
//	}
//	if (spec->dot == 1)
//	{
//		ft_putstrn1(spec->value.s, spec->precision);
//		if (spec->flag == '-')
//		{
//			while (spec->width-- > spec->len)
//				ft_putchar1(' ');
//		}
//	}
////	else if (spec->width < spec->len)
////		ft_putstr(spec->value.s);
////	else if (spec->flag == '-' && spec->dot == 1 && spec->precision > spec->len)
////		ft_putstr(spec->value.s);
//	else
//	{
//		ft_putstr1(spec->value.s);
//		if (spec->flag == '-')
//		{
//			while (spec->width-- > spec->len)
//				ft_putchar1(' ');
//		}
//	}
//}

//void 	ft_print_d1(t_spec *spec)
//{
//	int i = 0;
//
////	printf("[%d]", spec->precision);
////	if (spec->value.s == NULL)
////		spec->value.s = "(null)";
//	if (spec->value.d < 0)
//		spec->len +=1;
//	if (spec->precision > 0 && spec->precision < spec->len)
//		spec->precision = spec->len;
////	if (spec->precision == 0 && spec->dot == 1)
////		spec->len = 0 ;
//	if (spec->flag == ' ')
//	{
//		while (i++ < (spec->width - spec->len - spec->precision + spec->len))
//			ft_putchar1(' ');
//		ft_print_with_zeroes(spec);
////		ft_putnbr(spec->value.d);
//	}
//	else if (spec->flag == '-')
//	{
//		ft_putnbr(spec->value.d);
//		while (i++ < (spec->width - spec->len))
//			ft_putchar1(' ');
//	}
//	else if (spec->flag == '0')
//	{
////		printf("[%c]",spec->flag);
////		printf("[%d]",spec->width);
//		while (i++ < (spec->width - spec->len))
//			ft_putchar1('0');
//		ft_putnbr(spec->value.d);
//	}
//}
//
//void 	ft_print_X1(t_spec *spec)
//{
//	int len;
//	char c;
//
//	len = spec->len;
//	if (spec->flag == '-')
//	{
////		print_value(spec->value, spec->type, spec->precision, spec->len);
//		while (spec->precision > spec->len++)
//			ft_putchar1('0');
//		ft_putstr1(spec->value.X);
//
//		while (len++ < spec->width)
//			ft_putchar1(' ');
//	}
//	else
//	{
//		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
//		if (spec->dot && spec->precision > len)
//			spec->width = spec->width - spec->precision + len;
//		while (len++ < spec->width)
//			ft_putchar1(c);
////		print_value(spec->value, spec->type, spec->precision, spec->len);
//		while (spec->precision > spec->len++)
//			ft_putchar1('0');
//		ft_putstr1(spec->value.X);
//	}
//}
//
//void 	ft_print_x1(t_spec *spec)
//{
//	int len;
//	char c;
//
//	len = spec->len;
//	if (spec->flag == '-')
//	{
////		print_value(spec->value, spec->type, spec->precision, spec->len);
//		while (spec->precision > spec->len++)
//			ft_putchar1('0');
//		ft_putstr1(spec->value.x);
//
//		while (len++ < spec->width)
//			ft_putchar1(' ');
//	}
//	else
//	{
//		c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
//		if (spec->dot && spec->precision > len)
//			spec->width = spec->width - spec->precision + len;
//		while (len++ < spec->width)
//			ft_putchar1(c);
////		print_value(spec->value, spec->type, spec->precision, spec->len);
//		while (spec->precision > spec->len++)
//			ft_putchar1('0');
//		ft_putstr1(spec->value.x);
//	}
//}