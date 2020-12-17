#include "libft/libft.h"
#include "ft_printf.h"

int 	ft_printf(const char *str, ...)
{
	int k = 0;
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
			k+= ft_processor(spec);
			str = str + spec->len_after_perc ;
//			k += spec->len_after_perc;
		}
		else
		{
			k += write(1, str, 1);
			str++;
		}
	}
//	printf("\nk:%d", k);
	free(spec);
	va_end(ap);
	return (k);
}

//s p i точность в d если больше длины d то заполняет нулями
//d > len

//ширина бльше длины то возвращаю точность
//если точность

