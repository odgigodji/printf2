/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:56:22 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 20:58:02 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_flag_parser(char **str)
{
	char flag;

	flag = ' ';
	while ((**str == '0' || **str == '-'))
	{
		if (**str == '0' && flag != '-')
		{
			flag = '0';
		}
		if (**str == '-')
		{
			flag = '-';
		}
		(*str)++;
	}
	return (flag);
}

int		ft_width_parser(char **str, va_list ap, char *flag)
{
	int width;

	width = 0;
	if (ft_isdigit(**str) || **str == '*')
	{
		width = (**str == '*' ? va_arg(ap, int) : ft_atoi(*str));
		if (width < 0)
		{
			width *= -1;
			*flag = '-';
		}
	}
	while ((ft_isdigit(**str)) || (**str == '*'))
	{
		(*str)++;
	}
	return (width);
}

int		ft_precision_parser(char **str, va_list ap, int *dot)
{
	int precision;

	precision = 0;
	*dot = 0;
	if (**str == '.')
	{
		*dot = 1;
		(*str)++;
		if (ft_isdigit(**str) || **str == '*')
		{
			precision = (**str == '*' ? va_arg(ap, int) : ft_atoi(*str));
		}
	}
	while ((ft_isdigit(**str)) || (**str == '*'))
	{
		(*str)++;
	}
	return (precision);
}

t_value	ft_type_parser(char **str, va_list ap, char *type, int *len)
{
	t_value value;

	value = ft_val_init();
	if ((**str == 'd' || **str == 'i') && (*type = 'd'))
		value.d = va_arg(ap, int);
	if (**str == 'c' && (*type = 'c'))
		value.c = va_arg(ap, int);
	if (**str == 's' && (*type = 's'))
		value.s = va_arg(ap, char *);
	if (**str == 'u' && (*type = 'u'))
		value.u = va_arg(ap, unsigned int);
	if (**str == 'x' && (*type = 'x'))
		value.x = atoi_16(va_arg(ap, unsigned int), 0, &value.error, 1);
	if (**str == 'X' && (*type = 'X'))
		value.xup = atoi_16(va_arg(ap, unsigned int), 1, &value.error, 1);
	if (**str == 'p' && (*type = 'p'))
		value.p = atoi_16(va_arg(ap, unsigned long), 0, &value.error, 1);
	if (**str == '%' && (*type = '%'))
		*len = 1;
	if (!(ft_strchr("dcsuxiXp%", **str)))
		value.error = -1;
	(*str)++;
	return (value);
}

void	ft_parser(char *str, va_list ap, t_spec *spec)
{
	spec->len_after_perc = ft_strlen_type(str);
	spec->flag = ft_flag_parser(&str);
	spec->width = ft_width_parser(&str, ap, &spec->flag);
	spec->precision = ft_precision_parser(&str, ap, &spec->dot);
	spec->value = ft_type_parser(&str, ap, &spec->type, &spec->len);
}
