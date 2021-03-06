/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 07:47:51 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/07 10:54:00 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_temp_list		*save_data(t_glob *g)
{
	t_temp_list *head;
	t_temp_list *node;

	head = NULL;
	while (get_next_line(0, &g->cursor))
	{
		if (head == NULL)
		{
			head = (t_temp_list *)malloc(sizeof(t_temp_list));
			node = head;
		}
		node->str = g->cursor;
		node->next = (t_temp_list *)malloc(sizeof(t_temp_list));
		if (node->str == NULL || (ft_strcmp(node->str, "\0") == 0))
			error();
		node = node->next;
	}
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}
