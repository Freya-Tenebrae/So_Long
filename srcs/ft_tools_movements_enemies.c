/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_movements_enemies.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 13:53:02 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_swap(t_tiles **tiles_enemies, t_tiles **tiles_dest)
{
	(*tiles_dest)->type = (*tiles_enemies)->type;
	(*tiles_dest)->frame = (*tiles_enemies)->frame;
	(*tiles_dest)->var = (*tiles_enemies)->var;
	free((*tiles_dest)->path);
	(*tiles_dest)->path = (*tiles_enemies)->path;
	(*tiles_enemies)->type = '0';
	(*tiles_enemies)->frame = 0;
	(*tiles_enemies)->var = 0;
	(*tiles_enemies)->path = ft_strdup(BASIC_TILES);
	if ((*tiles_enemies)->path == NULL)
		return (-1);
	return (0);
}


static int	ft_moving(t_maps **maps, int pos_x, int pos_y, \
						t_enemies **enemies_ptr)
{
	t_tiles	*tiles_enemies;
	t_tiles	*tiles_dest;

	tiles_enemies = (*maps)->tiles;
	tiles_dest = (*maps)->tiles;
	while (tiles_enemies->x_pos != (*enemies_ptr)->x_pos || \
			tiles_enemies->y_pos != (*enemies_ptr)->y_pos)
		tiles_enemies = tiles_enemies->next;
	while (tiles_dest->x_pos != pos_x || tiles_dest->y_pos != pos_y)
		tiles_dest = tiles_dest->next;
	(*enemies_ptr)->x_last_pos = (*enemies_ptr)->x_pos;
	(*enemies_ptr)->y_last_pos = (*enemies_ptr)->y_pos;
	(*enemies_ptr)->x_pos = pos_x;
	(*enemies_ptr)->y_pos = pos_y;
	if (tiles_dest->type == 'P')
	{
		(*maps)->status_game = 1;
		(*maps)->n_frame = 0;
		return (0);
	}
	return (ft_swap(&tiles_enemies, &tiles_dest));
}

static int	ft_select_movement_p2(t_maps **maps, t_enemies **e_ptr, \
									int n_path)
{
	if (((*maps)->map[(*e_ptr)->y_pos + 1][(*e_ptr)->x_pos] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos + 1][(*e_ptr)->x_pos] == 'X') && \
		(n_path == 1 || ((*e_ptr)->x_pos != (*e_ptr)->x_last_pos || \
		(*e_ptr)->y_pos + 1 != (*e_ptr)->y_last_pos)))
			return (ft_moving(maps, (*e_ptr)->x_pos, (*e_ptr)->y_pos + 1, \
					e_ptr));
	else if (((*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos - 1] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos - 1] == 'X') && \
		(n_path == 1 || ((*e_ptr)->x_pos - 1 != (*e_ptr)->x_last_pos || \
		(*e_ptr)->y_pos != (*e_ptr)->y_last_pos)))
			return (ft_moving(maps, (*e_ptr)->x_pos - 1, (*e_ptr)->y_pos, \
					e_ptr));
	else if (((*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos + 1] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos + 1] == 'X') && \
		(n_path == 1 || ((*e_ptr)->x_pos + 1 != (*e_ptr)->x_last_pos || \
		(*e_ptr)->y_pos != (*e_ptr)->y_last_pos)))
			return (ft_moving(maps, (*e_ptr)->x_pos + 1, (*e_ptr)->y_pos, \
					e_ptr));
	return (-1);
}

static int	ft_select_movement(t_maps **maps, t_enemies **e_ptr)
{
	int n_path;

	n_path = 0;
	if ((*maps)->map[(*e_ptr)->y_pos - 1][(*e_ptr)->x_pos] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos - 1][(*e_ptr)->x_pos] == 'X')
		n_path += 1;
	if ((*maps)->map[(*e_ptr)->y_pos + 1][(*e_ptr)->x_pos] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos + 1][(*e_ptr)->x_pos] == 'X')
		n_path += 1;
	if ((*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos - 1] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos - 1] == 'X')
		n_path += 1;
	if ((*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos + 1] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos][(*e_ptr)->x_pos + 1] == 'X')
		n_path += 1;
	if (((*maps)->map[(*e_ptr)->y_pos - 1][(*e_ptr)->x_pos] == 'x' || \
		(*maps)->map[(*e_ptr)->y_pos - 1][(*e_ptr)->x_pos] == 'X') && \
		(n_path == 1 || ((*e_ptr)->x_pos != (*e_ptr)->x_last_pos || \
		(*e_ptr)->y_pos - 1 != (*e_ptr)->y_last_pos)))
			return (ft_moving(maps, (*e_ptr)->x_pos, (*e_ptr)->y_pos - 1, \
					e_ptr));
	else
		return ft_select_movement_p2(maps, e_ptr, n_path);
}

int	ft_move_enemies(t_maps **maps)
{
	t_enemies	*enemies_ptr;

	enemies_ptr = (*maps)->enemies;
	if ((*maps)->status_game == 0)
	{
		while (enemies_ptr != NULL)
		{
			if (ft_select_movement(maps, &enemies_ptr) != 0)
				return (-1);
			enemies_ptr = enemies_ptr->next;
		}
	}
	return (0);
}
