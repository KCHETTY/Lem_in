/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:39:48 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/23 15:37:57 by arnovan-         ###   ########.fr       */
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
	/*
	 * t_path *fst;
	if (g->f_path == NULL)
	{
		g->f_path = (t_path *)malloc(sizeof(t_path));
		fst = g->f_path;
	}
	fst->path = g->start;
	*/
	if (find_path(g, g->start))
		write(1, "success", 7);
	else
		write(1, "failure", 7);
}
