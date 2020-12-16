/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:23:07 by namerei           #+#    #+#             */
/*   Updated: 2020/12/13 23:23:50 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	q1(unsigned int nb)
{
	char	a;

	if (!nb)
		return ;
	q1(nb / 10);
	a = nb % 10 + '0';
	write(1, &a, 1);
}

void		ft_putnbr_unsigned(unsigned long nb)
{
//	if (nb == 0 || nb == -2147483648)
//	{
//		write(1, (nb == 0) ? "0" : "-2147483648", (nb == 0) ? 1 : 11);
//		return ;
//	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	q1(nb);
}
