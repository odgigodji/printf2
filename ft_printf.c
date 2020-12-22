#include "libft/libft.h"
#include "ft_printf.h"

//int g_res = 0;
//s,p,c,d - ok
//u,x,X - work


int 	ft_printf(const char *str, ...)
{
	va_list ap;
	t_spec *spec;

	g_res = 0;
	spec = (t_spec*)malloc(sizeof(t_spec));
	va_start(ap, str);
	while(*str)
	{
		if (*str == '%' && str++)
		{
			ft_parser((char *)str, ap, spec);// dlinu parsa
			if (spec->value.error == -1)
			{
				g_res = -1;
				break;
////				printf("%d", spec->value.error);
//				free(spec);
//				va_end(ap);
//				return (-1);
			}
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

//s p i точность в d если больше длины d то заполняет нулями
//d > len

//ширина бльше длины то возвращаю точность
//если точность

