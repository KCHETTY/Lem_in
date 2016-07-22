
#include "lem_in.h"

t_temp_list		*save_data(t_glob *g)
{
	t_temp_list *head;
	t_temp_list *node;


	while (get_next_line(0, &g->cursor))
	{
		if (head == NULL)
		{
			head = (t_temp_list *)malloc(sizeof(t_temp_list));
			node = head;
		}
		node->str = g->cursor;
		node->next = (t_temp_list *)malloc(sizeof(t_temp_list));
		node = node->next;
	}
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}
