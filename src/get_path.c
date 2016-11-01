/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 11:40:16 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/01 11:40:17 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_flag(t_data *check)
{
	if (check->flag == 0)
		return (1);
	return (0);
}

int		find_path(t_glob *g, t_data *node)
{
	int	i;

	i = 0;
	while (i < node->num_links)
	{
		if (ft_strcmp(node->room_name, g->end->room_name) == 0)
		{
			node->flag = 1;
			i = node->num_links;
		}
		else if (node->links[i] != NULL)
		{
			if (check_flag(node->links[i]))
			{
				node->flag = 1;
				find_path(g, node->links[i]);
			}
			else if (ft_strcmp(g->start->room_name, node->room_name) != 0)
				node->flag = -1;
		}
		i++;
	}
	return (1);
}

void	get_path(t_glob *g)
{
	if (find_path(g, g->start))
		return ;
	else
		error();
}
