/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/22 18:06:31 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//INCLUDE ALL INITIALIZED VARIABLES
//FREE SHIT BEFORE EXIT IN ERROR()

#include "lem_in.h"

int		main()
{
	t_glob		g;
	int	i = 0;

	g.ants = 0;
	g.data = save_data(&g);
	//printf("g.data: %p\n", g.data);
	if (get_map(&g))
	{
		get_data(&g);
		add_links(&g);
		while (i < g.num_rooms)
		{
			printf("ADDRESS: %p NAME: %s X: %d Y: %d\n", g.rooms[i], g.rooms[i]->room_name, g.rooms[i]->coord_x, g.rooms[i]->coord_y);
			i++;
		}
			
		printf("link : %p \n", g.rooms[0]->links[0]);
		printf("link1 : %p \n", g.rooms[1]->links[0]);
		printf("link2 : %p \n", g.rooms[2]->links[0]);
		//printf("start_flag : %i \n", g.start_flag);
		//printf("ant_flag : %i \n", g.ant_flag);
		//printf("end_flag : %i \n", g.end_flag);
		//printf("lines : %i \n", g.lines);
		//printf("num_links : %i \n", g.num_links);
		//printf("num_rooms : %i \n", g.num_rooms);
		//printf("ants: %li\n", g.ants);
	}
	
	return (0);
}

void	error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}
