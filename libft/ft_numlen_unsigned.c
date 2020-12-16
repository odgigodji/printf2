/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 23:30:29 by namerei           #+#    #+#             */
/*   Updated: 2020/12/13 23:30:51 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_numlen_unsigned(unsigned int n)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
