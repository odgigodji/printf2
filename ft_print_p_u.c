/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:36:28 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 21:36:30 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_spaces_p(t_spec *spec)
{
	int len;

	len = ft_strlen(spec->value.p) + 2;
	if (spec->width > len)
		return (spec->width - len);
	else
		return (0);
}

void	ft_print_p(t_spec *spec)
{
	int len;
	int spaces;

	spec->len = ft_strlen(spec->value.p);
	if (!spec->precision && spec->value.p[0] == '0' && spec->dot)
	{
		while (spec->width-- > 2)
			ft_putchar1(' ');
		ft_putstr1("0x");
		return ;
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

void	ft_print_p_add(t_spec *spec, int spaces)
{
	int		len;
	char	c;

	len = 0;
	c = (spec->flag == '0' && !spec->dot) ? '0' : ' ';
	if (spec->dot && spec->precision > len)
		spec->width = spec->width - spec->precision + len - 2;
	else
		spec->width = spec->width - len;
	while (len++ < spaces)
		ft_putchar1(c);
	ft_putstr1("0x");
	while (spec->precision > spec->len++)
		ft_putchar1('0');
	ft_putstr1(spec->value.p);
}

void	ft_print_u(t_spec *spec)
{
	spec->len = ft_numlen_unsigned(spec->value.u);
	if (!spec->precision && !spec->value.u && spec->dot)
	{
		while (spec->width--)
			ft_putchar1(' ');
		return ;
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
}

void	ft_print_u_add(t_spec *spec)
{
	char	c;
	int		len;

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
}
