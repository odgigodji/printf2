/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namerei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 22:00:03 by namerei           #+#    #+#             */
/*   Updated: 2020/12/22 22:00:05 by namerei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int g_res;

typedef struct		s_value
{
	long			d;
	char			c;
	char			*s;
	unsigned int	u;
	char			*x;
	char			*xup;
	char			*p;
	int				error;
}					t_value;

typedef struct		s_spec
{
	char			flag;
	int				width;
	int				precision;
	char			type;
	t_value			value;
	int				len;
	int				dot;
	int				len_after_perc;
}					t_spec;

int					ft_printf(const char *str, ...);
void				ft_parser(char *str, va_list ap, t_spec *spec);
void				ft_processor(t_spec *spec);
void				ft_putchar1(int c);
void				ft_putstr1(char *s);
void				ft_putstrn1(char *s, int n);
void				ft_putnbr1(long nb);
void				ft_putnbr_unsigned1(unsigned long nb);
void				ft_putnbr1(long nb);
int					ft_spaces_p(t_spec *spec);
void				ft_print_p(t_spec *spec);
void				ft_print_p_add(t_spec *spec, int spaces);
void				ft_print_u(t_spec *spec);
void				ft_print_u_add(t_spec *spec);
void				ft_print_s(t_spec *spec);
void				ft_print_x(t_spec *spec);
void				ft_print_x_add(t_spec *spec);
void				ft_print_x_up(t_spec *spec);
void				ft_print_x_up_add(t_spec *spec);
void				ft_print_with_zeroes(t_spec *spec);
void				ft_print_d(t_spec *spec);
void				ft_print_d_add(t_spec *spec);
void				ft_print_c(t_spec *spec);
void				ft_print_with_zeroes(t_spec *spec);
void				ft_print_d(t_spec *spec);
void				ft_print_d_add(t_spec *spec);
void				ft_print_c(t_spec *spec);
size_t				ft_strlen_type(const char *s);
char				ft_flag_parser(char **str);
t_value				ft_val_init(void);
t_value				ft_type_parser(char **str, va_list ap, \
					char *type, int *len);
int					ft_width_parser(char **str, va_list ap, char *flag);
int					ft_precision_parser(char **str, va_list ap, int *dot);
char				*atoi_16(unsigned long x, int flag_type, int *error, int i);

#endif
