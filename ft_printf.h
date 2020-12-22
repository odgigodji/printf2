#ifndef _FT_PRINTF_H_
#define _FT_PRINTF_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

//%[флаги][ширина][.точность]+[размер точности][тип]

int g_res;

typedef struct s_value
{
	long 	d;
	char 	c;
	char	*s;
	unsigned int u;
	char 	*x;
	char	*X;
	char	*p;
	int 	error;
}				t_value;

typedef struct	s_spec
{
	char	flag;
	int		width;
	int		precision;
	char 	type;
	t_value  value;
	int		len;
	int 	dot;
	int		len_after_perc;
}				t_spec;

int 	ft_printf(const char *, ...);
//void 	ft_parser(t_spec *spec, va_list ap, int *i, char *str);
void	ft_parser(char *str, va_list, t_spec *spec);
void	ft_processor(t_spec *spec);
void	ft_putchar1(int c);
void	ft_putstr1(char *s);
void	ft_putstrn1(char *s, int n);
void	ft_putnbr1(long nb);
void	ft_putnbr_unsigned1(unsigned long nb);
void	ft_putnbr1(long nb);
#endif