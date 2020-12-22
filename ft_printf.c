#include "libft/libft.h"
#include "ft_printf.h"


int 	ft_printf(const char *str, ...)//done
{
	va_list ap;
	t_spec *spec;

	g_res = 0;
	if (!(spec = (t_spec*)malloc(sizeof(t_spec))))
		return (-1);
	va_start(ap, str);
	while(*str)
	{
		if (*str == '%' && str++)
		{
			ft_parser((char *)str, ap, spec);
//			printf("%d",spec->value.error);
			if (spec->value.error == -1 && (g_res = -1))
				break ;
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

