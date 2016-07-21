/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:50:58 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/21 17:53:56 by kchetty          ###   ########.fr       */
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

static int	test_alpha(t_glob *g)
{
	char c;

	while (*g->cursor != '\0')
	{
		c = *g->cursor;
		if ((c >= 58 && c <= 126) || (c >= 33 && c <= 47))
		{
			return (1);
		}
		g->cursor++;
	}
	return (0);
}

static void	check_data(t_glob *g)
{
	g->is_space = 0;
	g->is_dash = 0;
	if (g->cursor[0] == 'L')
		error();
	g->lines++;
	while (*g->cursor != '\0')
	{
		if (*g->cursor == ' ')
			g->is_space++;
		else if (*g->cursor == '-')
			g->is_dash++;
		g->cursor++;
	}
	if (g->is_space == 2)
		g->num_rooms++;
	if (g->is_dash == 1)
		g->num_links++;
}

int			get_map(t_glob *g)
{
	/////// Intitialize in main ////////
	g->num_links = 0;
	g->num_rooms = 0;
	g->lines = 0;
	g->ant_flag = 0;
	g->start_flag = 0;
	g->end_flag = 0;
	///////////////////////////////////
	while (get_next_line(0, &g->cursor))
	{
		if (*g->cursor == '\0')
			error();
		if ((g->lines == 0) && (test_alpha(g) == 0))
			g->ant_flag = 1;
		if ((ft_strcmp("##start", g->cursor)) == 0)
			g->start_flag = 1;
		if ((ft_strcmp("##end", g->cursor)) == 0)
			g->end_flag = 1;
		if ((ft_strncmp("#", g->cursor, 1)) == 0)
			continue;
		check_data(g);
	}
	if (validate(g))
		return (1);
	return (0);
}
