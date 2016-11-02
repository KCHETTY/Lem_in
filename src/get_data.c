/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:26:07 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/02 11:00:37 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_addr(t_glob *g, int i)
{
	if (g->start_flag == 1)
	{
		g->start_flag = 0;
		g->start = g->rooms[i];
	}
	if (g->end_flag == 1)
	{
		g->end_flag = 0;
		g->end = g->rooms[i];
	}
}

void	get_data_2(t_glob *g, int i, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, ' ');
	g->rooms[i]->room_name = tmp[0];
	if (tmp[1][0] >= '0' && tmp[1][0] <= '9')
		g->rooms[i]->coord_x = ft_atoi(tmp[1]);
	else
		error();
	if (tmp[2][0] >= '0' && tmp[2][0] <= '9')
		g->rooms[i]->coord_y = ft_atoi(tmp[2]);
	else
		error();
	g->rooms[i]->flag = 0;
	g->rooms[i]->if_ant = 0;
	free(tmp);
}

void	get_data(t_glob *g)
{
	t_temp_list	*node;
	int			i;

	node = g->data;
	i = 0;
	g->rooms = (t_data **)malloc(sizeof(t_data) * g->num_rooms + 1);
	while (ft_strchr(node->str, '-') == NULL)
	{
		if (g->ants == 0)
			g->ants = ft_atoi(node->str);
		else if ((ft_strcmp("##start", node->str)) == 0)
			g->start_flag = 1;
		else if ((ft_strcmp("##end", node->str)) == 0)
			g->end_flag = 1;
		else if (*node->str != '#')
		{
			g->rooms[i] = (t_data *)malloc(sizeof(t_data));
			get_addr(g, i);
			get_data_2(g, i, node->str);
			i++;
		}
		node = node->next;
	}
	g->rooms[i] = NULL;
}
