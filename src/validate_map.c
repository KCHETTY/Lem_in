/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/11/02 10:59:18 by kchetty          ###   ########.fr       */
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
		if (ft_isprint(c) == 0)
			error();
		str++;
	}
	return (0);
}

static int	test_digit(char *str)
{
	char c;

	while (*str != '\0')
	{
		c = *str;
		if (ft_isdigit(c) == 0)
			error();
		str++;
	}
	return (0);
}

static void	check_data(t_glob *g, char *str)
{
	g->is_space = 0;
	g->is_dash = 0;
	if ((str[0] == 'L') || (str[0] == '\n') || (str[0] == ' '))
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

	node = g->data;
	while (node->next != NULL)
	{
		printf("%s\n", node->str);
		test_alpha(node->str);
		((g->lines == 0) && (test_digit(node->str) == 0)) ? g->ant_flag = 1 : 0;
		((ft_strcmp("##start", node->str)) == 0) ? g->start_flag = 1 : 0;
		((ft_strcmp("##end", node->str)) == 0) ? g->end_flag = 1 : 0;
		if ((ft_strncmp("#", node->str, 1)) == 0)
		{
			node = node->next;
			continue;
		}
		if (node->str == NULL)
			error();
		check_data(g, node->str);
		node = node->next;
	}
	if (validate(g))
		return (1);
	free(node);
	return (0);
}
