/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_enemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 12:21:43 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_free_enemies(t_enemies **enemies)
{
	t_enemies	*enemies_ptr;

	enemies_ptr = *enemies;
	while (enemies_ptr != NULL)
	{
		enemies_ptr = enemies_ptr->next;
		free(*enemies);
		*enemies = enemies_ptr;
	}	
}

static int	ft_call_init_enemies(t_maps **maps, t_enemies **enemies_ptr, int pos[2])
{
	t_enemies		*enemies_new;

	enemies_new = malloc(sizeof(t_enemies));
	if (enemies_new == NULL)
	{
		ft_free_maps(maps);
		return (-1);
	}
	enemies_new->x_pos = pos[0];
	enemies_new->x_last_pos = pos[0];
	enemies_new->y_pos = pos[1];
	enemies_new->y_last_pos = pos[1];
	if (*enemies_ptr == NULL)
	{
		(*maps)->enemies = enemies_new;
		*enemies_ptr = (*maps)->enemies;
	}
	else
	{
		(*enemies_ptr)->next = enemies_new;
		*enemies_ptr = (*enemies_ptr)->next;
	}
	(*enemies_ptr)->next = NULL;
	return (0);
}

void	ft_init_enemies(t_maps **maps)
{
	t_enemies	*enemies_ptr;
	int			pos[2];

	enemies_ptr = NULL;
	pos[1] = 0;
	while (pos[1] < (*maps)->y_lenght)
	{
		pos[0] = 0;
		while (pos[0] < (*maps)->x_lenght)
		{
			if ((*maps)->map[pos[1]][pos[0]] == 'X')
			{
				if (ft_call_init_enemies(maps, &enemies_ptr, pos) == -1)
					return ;
			}
			pos[0] += 1;
		}
		pos[1] += 1;
	}
}
