/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 11:40:34 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/01 11:51:24 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init(t_glob *g)
{
	g->check = 0;
	g->ants = 0;
	g->num_links = 0;
	g->num_rooms = 0;
	g->lines = 0;
	g->ant_flag = 0;
	g->start_flag = 0;
	g->end_flag = 0;
}

int		main(void)
{
	t_glob		g;

	init(&g);
	g.data = save_data(&g);
	if (get_map(&g))
	{
		get_data(&g);
		add_links(&g);
		get_path(&g);
		move_ant(&g);
	}
	else
		error();
	return (0);
}

void	error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}
