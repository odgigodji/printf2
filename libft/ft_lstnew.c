#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *res;//res ukazatel na t_list

    res = (t_list *)malloc(sizeof(t_list));
    if (!res)
        return (NULL);
    res -> content = content; //oznachaet pereiti po adresu i zapisat znachenie
    res -> next = NULL;
    return (res);
}
