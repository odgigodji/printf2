#include "ft_printf.h"

void	ft_putchar1(int c)
{
	write(1, &c, 1);
	g_res++;
}

void	ft_putstr1(char *s)
{
	while (*s)
	{
		ft_putchar1(*s++);
	}
}

void	ft_putstrn1(char *s, int n)
{
	while (*s && n--)
	{
		ft_putchar1(*s++);
	}
}

static void	q1(unsigned int nb)
{
	char	a;

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
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		g_res += write(1, "-", 1);
		nb = -nb;
	}
	q1(nb);
}

static void		q(int nb)
{
	char	a;

	if (!nb)
		return ;
	q(nb / 10);
	a = nb % 10 + '0';
	g_res += write(1, &a, 1);
}


void		ft_putnbr1(int nb)
{
	if (nb == 0 || nb == -2147483648)
	{
		g_res += write(1, (nb == 0) ? "0" : "-2147483648", (nb == 0) ? 1 : 11);
		return ;
	}
	if (nb < 0)
	{
		g_res += write(1, "-", 1);
		nb = -nb;
	}
	q(nb);
}
