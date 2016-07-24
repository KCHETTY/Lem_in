/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/23 18:01:00 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_glob		g;
	int	i = 0;
	int j = 0;


	g.ants = 0;
	g.num_links = 0;
	g.num_rooms = 0;
	g.lines = 0;
	g.ant_flag = 0;
	g.start_flag = 0;
	g.end_flag = 0;
	g.data = save_data(&g);
	//printf("g.data: %p\n", g.data);
	if (get_map(&g))
	{
		get_data(&g);
		add_links(&g);
		get_path(&g);
		move_ant(&g);
		while (i < g.num_rooms)
		{
			j = 0;
			printf("ADDRESS: %p NAME: %s X: %d Y: %d flag: %d\n",
					g.rooms[i], g.rooms[i]->room_name, g.rooms[i]->coord_x,
					g.rooms[i]->coord_y, g.rooms[i]->flag);
			while (g.rooms[i]->links[j] != NULL)
			{
				printf("LINKS: %p\n", g.rooms[i]->links[j]);
				j++;
			}
			i++;
		}
		//ant_path(&g);
		/*
		printf("start_flag : %i \n", g.start_flag);
		printf("ant_flag : %i \n", g.ant_flag);
		printf("end_flag : %i \n", g.end_flag);
		printf("lines : %i \n", g.lines);
		printf("num_links : %i \n", g.num_links);
		printf("num_rooms : %i \n", g.num_rooms);
		printf("ants: %li\n", g.ants);
		*/
	}
	return (0);
}

void	error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}
