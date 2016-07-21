/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:26:07 by kchetty           #+#    #+#             */
/*   Updated: 2016/07/21 18:08:40 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	malloc_rooms(t_glob *g)
{
	int	i;

	i = 0;
	printf("NUM_ROOMS: %d\n", g->num_rooms);
	while (i < g->num_rooms)
	{
		g->rooms[i] = (t_data *)malloc(sizeof(t_data));
		if (g->rooms[i] == NULL)
			error();
		i++;
	}
}

void	get_data(t_glob *g)
{
	char	*line;
	printf("TEST\n");
	malloc_rooms(g);
	//g->rooms = (t_data **)malloc(sizeof(t_data) * g->num_rooms + 1);
	//printf("addres: %p\n", g->rooms[1]);
	g->ants = 0;
	while (get_next_line(0, &line))
	{
		printf("LINE: %s\n", line);
		if (g->ants == 0)
			g->ants = ft_atoi(line);	
	}

}
