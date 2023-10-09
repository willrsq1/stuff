

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;
	t_list *new_next;

	lst = *begin_list;
	while (lst && lst->next)
	{
		if (cmp(lst->next->data, data_ref) == 0)
		{
			new_next = lst->next->next;
			free(lst->next);
			lst->next = new_next;
		}
		else
			lst = lst->next;
	}
	lst = *begin_list;
	if (cmp(lst->data, data_ref) == 0)
	{
		*begin_list = lst->next;
		free(lst);
	}
}


#include <stdio.h>
#include <string.h>

void	print_list(t_list **begin_list)
{
	t_list *cur = *begin_list;
	while (cur != 0)
	{
		printf("%s\n", (char *)cur->data);
		cur = cur->next;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list **begin_list = &aa;

	print_list(begin_list);
	printf("----------\n");
	ft_list_remove_if(begin_list, straa, strcmp);
	ft_list_remove_if(begin_list, strbb, strcmp);
	ft_list_remove_if(begin_list, strcc, strcmp);
	ft_list_remove_if(begin_list, straa, strcmp);
	print_list(begin_list);
}