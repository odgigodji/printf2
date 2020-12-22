/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 21:01:18 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 21:01:20 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** len before type symbol
*/

size_t	ft_strlen_type(const char *s)
{
	unsigned long len;

	len = 0;
	while (s[len])
	{
		if (!(ft_strchr("dcsuxiXp%", s[len])))
			len++;
		else
			return (size_t)(len + 1);
	}
	return (0);
}

/*
** initialisation of structure value
*/

t_value	ft_val_init(void)
{
	t_value value;

	value.d = 0;
	value.c = '\0';
	value.s = "\0";
	value.u = 0;
	value.x = "\0";
	value.xup = "\0";
	value.p = "\0";
	value.error = 0;
	return (value);
}

/*
** atoi for 16 base:
** flag 1 for X
** flag 0 for x and p
*/

char	*atoi_16(unsigned long x, int flag_type, int *error, int i)
{
	unsigned long	tmp;
	char			*c;

	tmp = x;
	while (tmp >= 16 && i++)
		tmp = tmp / 16;
	if (!(c = (char *)malloc(i + 1)))
	{
		*error = -1;
		return (NULL);
	}
	c[i] = '\0';
	tmp = x;
	while (i > 0)
	{
		x %= 16;
		if (x >= 10)
			c[i - 1] = (char)((flag_type == 0) ? (x - 10 + 97) : (x - 10 + 65));
		else
			c[i - 1] = (char)(x + 48);
		tmp /= 16;
		x = tmp;
		i--;
	}
	return (c);
}
