/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:51:51 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 21:51:52 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	q1(unsigned int nb)
{
	char a;

	if (!nb)
		return ;
	q1(nb / 10);
	a = nb % 10 + '0';
	g_res += write(1, &a, 1);
}

void		ft_putnbr_unsigned1(unsigned long nb)
{
	if (nb == 0)
	{
		g_res += write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		g_res += write(1, "-", 1);
		nb = -nb;
	}
	q1(nb);
}

static void	q(long nb)
{
	char a;

	if (!nb)
		return ;
	q(nb / 10);
	a = nb % 10 + '0';
	g_res += write(1, &a, 1);
}

void		ft_putnbr1(long nb)
{
	if (nb == 0)
	{
		g_res += write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		g_res += write(1, "-", 1);
		nb = -nb;
	}
	q(nb);
}
