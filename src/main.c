/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:35:35 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/21 18:08:42 by kchetty          ###   ########.fr       */
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
	printf("SSJSJJSJSJSJSS\n");
	if (get_map(&g))
	{	printf("HIT SS\n ");
		get_data(&g);
		
		while (i < g.num_rooms)
		{
			printf("ADDRESS: %p\n NAME: %s\n tesy: %d\n", g.rooms[i], g.rooms[i]->room_name, g.rooms[i]->coord_x);//, g.rooms[i]->coord_y);
			i++;
		}
		printf("ant_flag : %i \n", g.ant_flag);
		printf("start_flag : %i \n", g.start_flag);
		printf("end_flag : %i \n", g.end_flag);
		printf("lines : %i \n", g.lines);
		printf("num_links : %i \n", g.num_links);
		printf("num_rooms : %i \n", g.num_rooms);
		printf("ants: %li\n", g.ants);
	}
//	printf("ant_flag : %i \n" g->);
	
	return (0);
}

void	error(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}
