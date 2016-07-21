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

	if (get_map(&g))
	{
		get_data(&g);
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
