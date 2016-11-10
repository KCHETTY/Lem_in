/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchetty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 11:41:16 by kchetty           #+#    #+#             */
/*   Updated: 2016/11/07 11:31:22 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	move_ants_onward(t_glob *g, t_path *rm, int i)
{
	if ((rm->next->is_ant == 1) && (rm->next != NULL) && (i >= 0))
	{
		move_ants_onward(g, rm->next, --i);
	}
	else if (ft_strcmp(rm->room_name, g->end->room_name) == 0)
	{
		rm->is_ant = 0;
	}
	else
	{
		rm->next->is_ant = 1;
		if (ft_strcmp(rm->room_name, g->start->room_name) != 0)
			rm->is_ant = 0;
		if (i <= g->ants)
			ft_printf("L%d-%s ", i, rm->next->room_name);
		return ;
	}
}

void	march_ants(t_glob *g)
{
	t_path	*current;
	t_path	*start;
	int		i;

	i = 1;
	start = g->f_path;
	current = g->f_path;
	while (start->is_ant >= 0)
	{
		if (current->next->is_ant == 0)
		{
			current->next->is_ant = 1;
			if (i <= g->ants)
				ft_printf("L%d-%s\n", i, current->next->room_name);
			else if (i <= g->ants + 4)
				ft_printf("\n");
			i++;
		}
		else
			move_ants_onward(g, current, i);
		start->is_ant -= 1;
	}
}

void	set_ants(t_glob *g)
{
	t_path	*new;
	int		i;

	i = 0;
	new = g->f_path;
	while (new->next != NULL)
	{
		i++;
		new = new->next;
	}
	g->f_path->is_ant = g->f_path->is_ant * i;
}

void	write_list(t_glob *g)
{
	t_path	*current;
	int		i;

	i = 0;
	g->f_path = (t_path *)malloc(sizeof(t_path));
	current = g->f_path;
	while (g->tmp1[i] != '\0')
	{
		current->room_name = g->tmp1[i];
		if (g->check == 0)
		{
			current->is_ant = g->ants;
			g->check = 1;
		}
		else
			current->is_ant = 0;
		current->next = (t_path *)malloc(sizeof(t_path));
		current = current->next;
		i++;
	}
	current->end = 2;
	current->next = NULL;
	set_ants(g);
	free(current);
}

void	move_ant(t_glob *g)
{
	int	i;
	int	j;

	j = 1;
	i = -1;
	g->tmp1[0] = strdup(g->start->room_name);
	while (i < g->num_links)
	{
		i++;
		if (g->start->links[i]->flag == 1)
		{
			g->tmp1[j] = strdup(g->start->links[i]->room_name);
			if (g->start->links[i] != NULL)
			{
				g->start = g->start->links[i];
				j++;
				i = -1;
			}
			if (ft_strcmp(g->start->room_name, g->end->room_name) == 0)
				i = g->num_links;
		}
	}
	write_list(g);
	ft_printf("\n");
	march_ants(g);
}
