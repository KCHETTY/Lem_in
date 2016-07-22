/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:26:07 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/22 14:06:05 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/////link Up First And last nodes

void	get_data_2(t_glob *g, int i, char *str)
{
	char	**tmp;
	
	tmp = ft_strsplit(str, ' ');
	printf("TEMP: %s\n", tmp[0]);
	g->rooms[i]->room_name = tmp[0];
	if (tmp[1][0] >= '0' && tmp[1][0] <= '9')
		g->rooms[i]->coord_x = ft_atoi(tmp[1]);
	else
		error();
	if (tmp[2][0] >= '0' && tmp[2][0] <= '9')
	{
		printf("TMP2: %s\n", tmp[2]);
		g->rooms[i]->coord_y = ft_atoi(tmp[2]);
	}
	g->rooms[i]->flag = 0;
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
		if(g->ants == 0)
			g->ants = ft_atoi(node->str);
		else if (*node->str != '#')
		{
			g->rooms[i] = (t_data *)malloc(sizeof(t_data));
			get_data_2(g, i, node->str);
			i++;				
		}	
		node = node->next;	
	}
	g->rooms[i] = NULL;
}
