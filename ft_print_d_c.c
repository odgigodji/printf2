/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:32:11 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 21:32:13 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_with_zeroes(t_spec *spec)
{
	int num_zero;

	if (spec->dot && !spec->precision && !spec->value.d && spec->width == -1)
		return ;
	if (spec->precision == 0 && spec->dot == 1 && spec->value.d == 0)
	{
		ft_putchar1(' ');
		return ;
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
}

void	ft_print_d(t_spec *spec)
{
	int len;

	len = spec->len;
	if (spec->flag == '-')
	{
		(spec->value.d < 0) ? ft_putchar1('-') : 0;
		while (spec->precision > len++)
			ft_putchar1('0');
		if (spec->dot == 1 && !spec->precision && !spec->value.d)
		{
			if (spec->width == 0)
				return ;
			ft_putchar1(' ');
		}
		else
		{
			ft_putnbr1((spec->value.d < 0) ? -1 * spec->value.d : \
			spec->value.d);
			len = (spec->value.d < 0 ? len + 1 : len);
		}
		while (len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
		ft_print_d_add(spec);
}

void	ft_print_d_add(t_spec *spec)
{
	int len_or_pres;

	if (spec->value.d < 0)
	{
		len_or_pres = (spec->precision > spec->len && spec->dot == 1) ? \
		spec->precision + 1 : spec->len + 1;
	}
	else
		len_or_pres = (spec->precision > spec->len) ? spec->precision : \
		spec->len;
	if ((spec->width && spec->flag == '0' && spec->value.d < 0) && \
	(!spec->dot || (spec->precision < 0 && spec->dot)))
	{
		ft_putchar1('-');
		spec->value.d *= -1;
	}
	while (spec->width-- > len_or_pres)
	{
		if (spec->dot && spec->precision >= 0)
			spec->flag = ' ';
		ft_putchar1((spec->flag == '0' || \
		(!spec->dot && spec->flag != ' ')) ? '0' : ' ');
	}
	ft_print_with_zeroes(spec);
}

void	ft_print_c(t_spec *spec)
{
	spec->len = 1;
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
}
