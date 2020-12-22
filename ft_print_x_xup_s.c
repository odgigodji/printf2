/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_xup_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:40:38 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 21:40:43 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(t_spec *spec)
{
	int i;

	i = 0;
	if (spec->precision > 0 && spec->precision < spec->len)
		spec->len = spec->precision;
	if (spec->precision == 0 && spec->dot == 1)
		spec->len = 0;
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
}

void	ft_print_x(t_spec *spec)
{
	spec->len = ft_strlen(spec->value.x);
	if (!spec->precision && spec->value.x[0] == '0' && spec->dot)
	{
		while (spec->width--)
			ft_putchar1(' ');
		free(spec->value.x);
		return ;
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
	free(spec->value.x);
}

void	ft_print_x_add(t_spec *spec)
{
	char	c;
	int		len;

	spec->len = ft_strlen(spec->value.x);
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

void	ft_print_x_up(t_spec *spec)
{
	spec->len = ft_strlen(spec->value.xup);
	if (!spec->precision && spec->value.xup[0] == '0' && spec->dot)
	{
		while (spec->width--)
			ft_putchar1(' ');
		free(spec->value.xup);
		return ;
	}
	if (spec->flag == '-')
	{
		while (spec->precision > spec->len++)
			ft_putchar1('0');
		ft_putstr1(spec->value.xup);
		while (spec->len++ <= spec->width)
			ft_putchar1(' ');
	}
	else
	{
		ft_print_x_up_add(spec);
	}
	free(spec->value.xup);
}

void	ft_print_x_up_add(t_spec *spec)
{
	int		len;
	char	c;

	spec->len = ft_strlen(spec->value.xup);
	len = spec->len;
	c = ((spec->flag == '0') && (!spec->dot || (spec->precision < 0 && \
				spec->width)) ? '0' : ' ');
	if (spec->dot && spec->precision > len)
		spec->width = spec->width - spec->precision + len;
	while (len++ < spec->width)
		ft_putchar1(c);
	while (spec->precision > spec->len++)
		ft_putchar1('0');
	ft_putstr1(spec->value.xup);
}
