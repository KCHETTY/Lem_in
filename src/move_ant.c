
#include "lem_in.h"

void	move_ants_onward(t_glob *g, t_path *rm, int i)
{
	if (rm->next->is_ant == 1)
	{
		move_ants_onward(g, rm->next , --i);
	}
	if (rm->next->is_ant == 0 ||  rm->next->end == 2)
	{
		rm->next->is_ant = 1;
		if (ft_strcmp(rm->room_name, g->start->room_name) != 0)
			rm->is_ant = 0;
		rm->next->ant_name = i;
		printf("HIIII: %s\n" , rm->next->room_name);
		//rm->ant_name = rm->next->ant_name + 1;
		printf("L%d-%s ", rm->next->ant_name, rm->next->room_name);
		return ;
	}
}

void	march_ants(t_glob *g)
{
	t_path *current;
	t_path *start;
	int i;

	i = 1;
	start = g->f_path;
	current = g->f_path;
	printf("start->is_ant: %d\n", start->is_ant);
	while (start->is_ant >= 0)
	{
		if (current->next->is_ant == 0)
		{
		  	current->next->is_ant = 1;
			//current->next->ant_name = i;
			//printf("PUSSY");
			printf("L%d-%s\n", i, current->next->room_name);
		}
		else
		{
			//current = g->f_path;
			move_ants_onward(g, current, i);
		}
		start->is_ant -= 1; 
		i++;
	}
}

void	write_list(t_glob *g)
{
	t_path *current;
	int	i;
	int check;

	i = 0;
	check = 0;
	g->f_path = (t_path *)malloc(sizeof(t_path));
	current = g->f_path;
	while (g->tmp1[i] != '\0')
	{
		current->room_name = g->tmp1[i];
		if (check == 0)
		{
			current->is_ant = g->ants;
			check = 1;
		}
		else
			current->is_ant = 0;
		current->next = (t_path *)malloc(sizeof(t_path));
		current = current->next;
		i++;
	}
	current->end = 2;
	current->next = NULL;
	free(current);
}

void	move_ant(t_glob *g)
{
	int i;
	int j;

	j = 1;
	i = -1;
	g->tmp1[0] = strdup(g->start->room_name);
	while (i < g->num_links)
	{
		i++;
		printf("EYE : %d\n", i);
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

	i = 0;
	while (g->tmp1[i] != '\0')
	{
		printf("THSGS SSS: %s\n", g->tmp1[i]);
		i++;
	}
	write_list(g);
	printf("SLOOOOOTS\n");
	march_ants(g);
}
