#include "ft_printf.h"

//если точность больше длины
int 	ft_spaces_p(t_spec *spec)
{
	int len;

	len = ft_strlen(spec->value.p) + 2;
	if (spec->width > len)
		return (spec->width - len);
	else
		return (0);
}//done

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
			ft_putchar1('-');
		while (num_zero-- && spec->len++)
			ft_putchar1('0');
		if (spec->value.d < 0)
			ft_putnbr1(-1 * spec->value.d);
		else
			ft_putnbr1(spec->value.d);
	}
}//done

void 	ft_print_d_add(t_spec *spec)
{
//	int len;
	int hz;

//	len = spec->len;
	hz = 0;
	if (spec->value.d < 0)
	{
		hz = (spec->precision > spec->len && spec->dot == 1) ? \
		spec->precision + 1 : spec->len + 1;
	}
	else
		hz = (spec->precision > spec->len) ? spec->precision  : spec->len;
	if ((spec->width && spec->flag == '0' && spec->value.d<0 ) && \
	(!spec->dot || (spec->precision < 0 && spec->dot)))
	{
		ft_putchar1('-');
		spec->value.d *= -1;
	}
	while(spec->width-- > hz)
	{
		if (spec->dot && spec->precision >= 0)
			spec->flag = ' ';
		ft_putchar1((spec->flag == '0' || \
		(!spec->dot && spec->flag !=' ')) ? '0' : ' ');
	}
	ft_print_with_zeroes(spec);
}//done

void 	ft_print_d(t_spec *spec)
{
	int len;

	len = spec->len;
	if (spec->flag == '-')
	{
		if (spec->value.d < 0)
			ft_putchar1('-');
		while (spec->precision > len++ )
			ft_putchar1('0');
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
		ft_print_d_add(spec);
}//done

void	ft_print_s(t_spec *spec)
{
	int i = 0;

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
		while (i++ < (spec->width - spec->len))
			ft_putchar1('0');
		ft_putstrn1(spec->value.s, spec->len);
	}
}//done

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
		ft_putchar1((spec->type == '%')\
		? '%' : spec->value.c);
		while (spec->width-- > 1)
			ft_putchar1(' ');
	}
}//done

void	ft_print_u_add(t_spec *spec)
{
	char c;
	int len;

	len = spec->len;
	c = ((spec->flag == '0') && (!spec->dot || (spec->precision < 0 && \
				spec->width)) ? '0' : ' ');
	if (spec->dot && spec->precision > len)
		spec->width = spec->width - spec->precision + len;
	while (len++ < spec->width)
		ft_putchar1(c);
	while (spec->precision > spec->len++)
		ft_putchar1('0');
	ft_putnbr_unsigned1(spec->value.u);
}//done

void 	ft_print_u(t_spec *spec)
{
	if (!spec->precision && !spec->value.u && spec->dot)
	{
		while (spec->width--)
			ft_putchar1(' ');
		return;
	}
	if (spec->flag == '-')
	{
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putnbr_unsigned1(spec->value.u);
		while (spec->len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
	{
		ft_print_u_add(spec);
	}
}//done

void 	ft_print_x_add(t_spec *spec)
{
	char c;
	int len;

	len = spec->len;
	c = ((spec->flag == '0') && (!spec->dot || (spec->precision < 0 && \
				spec->width)) ? '0' : ' ');
	if (spec->dot && spec->precision > len)
		spec->width = spec->width - spec->precision + len;
	while (len++ < spec->width)
		ft_putchar1(c);
	while (spec->precision > spec->len++)
		ft_putchar1('0');
	ft_putstr1(spec->value.x);
}

void 	ft_print_x(t_spec *spec)
{
	if (!spec->precision && spec->value.x[0] == '0' && spec->dot)
	{
		while (spec->width--)
			ft_putchar1(' ');
		return;
	}
	if (spec->flag == '-')
	{
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.x);
		while (spec->len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
		ft_print_x_add(spec);
//	free(spec->value.x);
}//done

void 	ft_print_X_add(t_spec *spec)
{
	int len;
	char c;

	len = spec->len;
	c = ((spec->flag == '0') && (!spec->dot || (spec->precision < 0 && \
				spec->width)) ? '0' : ' ');
	if (spec->dot && spec->precision > len)
		spec->width = spec->width - spec->precision + len;
	while (len++ < spec->width)
		ft_putchar1(c);
	while (spec->precision > spec->len++)
		ft_putchar1('0');
	ft_putstr1(spec->value.X);
}//done

void 	ft_print_X(t_spec *spec)
{
	if (!spec->precision && spec->value.X[0] == '0' && spec->dot)
	{
		while (spec->width--)
			ft_putchar1(' ');
		return;
	}
	if (spec->flag == '-')
	{
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.X);

		while (spec->len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
	{
		ft_print_X_add(spec);
	}
}//done

void 	ft_print_p_add(t_spec *spec, int spaces)
{
	int len;
	char c;

	len = 0;
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
}//done

void 	ft_print_p(t_spec *spec)//done
{
	int len;
	int spaces;

	if (!spec->precision && spec->value.p[0] == '0' && spec->dot)
	{
		while (spec->width-- > 2)
			ft_putchar1(' ');
		ft_putstr1("0x");
		return;
	}
	spaces = ft_spaces_p(spec);
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
		ft_print_p_add(spec, spaces);
}

void	ft_processor(t_spec *spec)
{
//	printf("flag:'%c'\nwidth:%d\nprecision:%d\ntype:%c\nlen_value:%d\n"
//		   "dot:%d\n-----------------------------------------------\n", \
//    spec->flag, spec->width, spec->precision, spec->type, spec->len,
//		   spec->dot);
//	printf("VALUES:\nd:%d\nc:%c\nu:%u\nx:%s\nX:%s\np:%s\ns:%s\n" ,\
//	spec->value.d, spec->value.c, spec->value.u, spec->value.x, \
//	spec->value.X, spec->value.p, spec->value.s);
//	printf("\nPROC:");
	if (spec->value.error == -1)
		return ;
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
}//done
