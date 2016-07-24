/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/23 18:01:00 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_glob		g;

	g.ants = 0;
	g.num_links = 0;
	g.num_rooms = 0;
	g.lines = 0;
	g.ant_flag = 0;
	g.start_flag = 0;
	g.end_flag = 0;
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
