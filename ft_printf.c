/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:48:24 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 21:48:27 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar1(int c)
{
	write(1, &c, 1);
	g_res++;
}

void	ft_putstrn1(char *s, int n)
{
	while (*s && n--)
	{
		ft_putchar1(*s++);
	}
}

void	ft_processor(t_spec *spec)
{
	if (spec->type == 'd')
	{
		spec->len = ft_numlen(spec->value.d);
		ft_print_d(spec);
	}
	if (spec->type == 's')
	{
		spec->value.s = (!spec->value.s ? "(null)" : spec->value.s);
		spec->len = ft_strlen(spec->value.s);
		ft_print_s(spec);
	}
	if (spec->type == 'c' || spec->type == '%')
		ft_print_c(spec);
	if (spec->type == 'u')
		ft_print_u(spec);
	if (spec->type == 'x')
		ft_print_x(spec);
	if (spec->type == 'p')
	{
		ft_print_p(spec);
		free(spec->value.p);
	}
	if (spec->type == 'X')
		ft_print_x_up(spec);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_spec	*spec;

	g_res = 0;
	if (!(spec = (t_spec*)malloc(sizeof(t_spec))))
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && str++)
		{
			ft_parser((char *)str, ap, spec);
			if (spec->value.error == -1 && (g_res = -1))
				break ;
			ft_processor(spec);
			str = str + spec->len_after_perc;
		}
		else
			ft_putchar1(*str++);
	}
	free(spec);
	va_end(ap);
	return (g_res);
}
