/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 11:38:00 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/23 14:35:15 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_num(char *name, t_glob *g)
{
	int i;

	i = 0;
	while (i < g->num_rooms)
	{
		if (ft_strcmp(g->rooms[i]->room_name, name) == 0)
			return (i);
		i++;
	}
	error();
	return (0);
}

t_data	*get_adress(t_glob *g, char *name)
{
	t_temp_list *node;
	char		**stuff;

	if (g->tmp == NULL)
		node = g->data;
	else
		node = g->tmp;
	while (node->next != NULL)
	{
		if (ft_strchr(node->str, '-') != NULL)
		{
			g->tmp = node->next;
			stuff = ft_strsplit(node->str, '-');
			if (ft_strcmp(stuff[0], name) == 0)
				return (g->rooms[get_num(stuff[1], g)]);
		}
		node = node->next;
	}
	return (NULL);
}

void	write_links(t_glob *g, int links, int i)
{
	int	j;

	j = 0;
	if (links > 0)
	{
		g->rooms[i]->links = (t_data **)malloc(sizeof(t_data) * links + 1);
		while (j < links)
		{
			g->rooms[i]->links[j] = get_adress(g, g->rooms[i]->room_name);
			j++;
		}
		g->rooms[i]->links[j] = NULL;
	}
}

int		get_link_num(t_glob *g, char *ref)
{
	t_temp_list		*node;
	int				num_links;
	char			**data;

	node = g->data;
	num_links = 0;
	while (node->next != NULL)
	{
		if (ft_strchr(node->str, '-') != NULL)
		{
			data = ft_strsplit(node->str, '-');
			if (data[0] == data[1])
				error();
			if ((ft_strcmp(ref, data[0]) == 0) ||
					(ft_strcmp(ref, data[1]) == 0))
				num_links += 1;
		}
		node = node->next;
	}
	return (num_links);
}

void	add_links(t_glob *g)
{
	int i;
	int	links;

	g->tmp = NULL;
	i = 0;
	while (i < g->num_rooms)
	{
		links = get_link_num(g, g->rooms[i]->room_name);
		g->rooms[i]->num_links = links;
		write_links(g, links, i);
		g->tmp = NULL;
		i++;
	}
}
