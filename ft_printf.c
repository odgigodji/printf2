#include "libft/libft.h"
#include "ft_printf.h"

//int g_res = 0;
//s,p,c,d - ok
//u,x,X - work


int 	ft_printf(const char *str, ...)
{
	g_res = 0;
	size_t str_len;
	va_list ap;
	t_spec *spec;

	spec = (t_spec*)malloc(sizeof(t_spec));
	va_start(ap, str);
	str_len = ft_strlen(str);
//	while(*str)

	while(*str)
	{
		if (*str == '%' && str++)
		{
//			str++;
			ft_parser((char *)str, ap, spec);// dlinu parsa
			ft_processor(spec);
			str = str + spec->len_after_perc ;
//			k += spec->len_after_perc;
		}
		else
		{
			ft_putchar1(*str);
//			g_res += write(1, str, 1);
			str++;
		}
	}
//	printf("\nk:%d", k);
	free(spec);
	va_end(ap);
	return (g_res);
}

//s p i точность в d если больше длины d то заполняет нулями
//d > len

//ширина бльше длины то возвращаю точность
//если точность

