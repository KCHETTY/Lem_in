/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:13:57 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/21 18:08:45 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct				s_temp_list
{
	char	*str;
	struct s_temp_list *next;
}							t_temp_list;

typedef	struct				s_data
{
	int						room_type;
	int						flag;
	char					*room_name;
	int						coord_x;
	int						coord_y;
	struct	s_data			**links;
}							t_data;

typedef struct				s_glob
{
	int						num_rooms;
	long int				ants;
	int						num_links;
	int						lines;
	int						ant_flag;
	int						start_flag;
	int						end_flag;
	int						is_space;
	int						is_dash;
	char					*cursor;
	t_temp_list				*data;
	t_data					*start;
	t_data					**rooms;
	t_data					*end;
}							t_glob;

int							get_map(t_glob *g);
void						get_data(t_glob *g);
t_temp_list					*save_data(t_glob *g);
void						error(void);
void						add_links(t_glob *g);
#endif
