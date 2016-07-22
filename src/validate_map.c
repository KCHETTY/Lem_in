/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/22 08:30:14 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	validate(t_glob *g)
{
	if ((g->start_flag != 1) || (g->end_flag != 1) || (g->ant_flag != 1)
			|| (g->num_links < 1) || (g->num_rooms < 2))
	{
		error();
		return (-1);
	}
	return (1);
}

static int	test_alpha(char *str)
{
	char c;

	while (*str != '\0')
	{
		c = *str;
		if ((c >= 58 && c <= 126) || (c >= 33 && c <= 47))
		{
			return (1);
		}
		str++;
	}
	return (0);
}

static void	check_data(t_glob *g, char *str)
{
	g->is_space = 0;
	g->is_dash = 0;
	if (str[0] == 'L')
		error();
	g->lines++;
	while (*str != '\0')
	{
		if (*str == ' ')
			g->is_space++;
		else if (*str == '-')
			g->is_dash++;
		str++;
	}
	if (g->is_space == 2)
		g->num_rooms++;
	if (g->is_dash == 1)
		g->num_links++;
}

int			get_map(t_glob *g)
{
	t_temp_list	*node;
	/////// Intitialize in main ////////
	g->num_links = 0;
	g->num_rooms = 0;
	g->lines = 0;
	g->ant_flag = 0;
	g->start_flag = 0;
	g->end_flag = 0;
	///////////////////////////////////
	node = g->data;
	printf("NODE: %p\n", node);
	while (node->next != NULL)
	{
		printf("node->str: %s\n" ,node->str);
		if (node->str == NULL)
			error();
		if ((g->lines == 0) && (test_alpha(node->str) == 0))
			g->ant_flag = 1;
		if ((ft_strcmp("##start", node->str)) == 0)
			g->start_flag = 1;
		if ((ft_strcmp("##end", node->str)) == 0)
			g->end_flag = 1;
		if ((ft_strncmp("#", node->str, 1)) == 0)
		{
			node = node->next;
			continue;
		}
		check_data(g, node->str);
		node = node->next;
	}
	if (validate(g))
		return (1);
	free(node);
	return (0);
}
