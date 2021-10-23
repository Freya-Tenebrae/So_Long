/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 09:32:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	ft_get_player_pos(t_maps **maps, int (*pos)[2])
{
	t_tiles	*tmp_tiles;

	tmp_tiles = (*maps)->tiles;
	while (tmp_tiles->type != 'P')
		tmp_tiles = tmp_tiles->next;
	(*pos)[0] = tmp_tiles->x_pos;
	(*pos)[1] = tmp_tiles->y_pos;
}

static int	ft_can_move(t_maps **maps, int pos_x, int pos_y, int keycode)
{
	t_tiles	*tmp_tiles;

	tmp_tiles = (*maps)->tiles;
	if (keycode == 'w')
		pos_y -= 1;
	else if (keycode == 'a')
		pos_x -= 1;
	else if (keycode == 's')
		pos_y += 1;
	else if (keycode == 'd')
		pos_x += 1;
	while (tmp_tiles->x_pos != pos_x || tmp_tiles->y_pos != pos_y)
		tmp_tiles = tmp_tiles->next;
	if (tmp_tiles->type == 'X')
		return (-2);
	if (tmp_tiles->type == '0')
		return (0);
	if (tmp_tiles->type == 'C')
		return (1);
	if (tmp_tiles->type == 'E' && \
		(*maps)->collectible_count == (*maps)->collectible_total)
		return (2);
	else
		return (-1);
}

static int	ft_swap(t_tiles **tiles_player, t_tiles **tiles_dest)
{
	(*tiles_dest)->type = (*tiles_player)->type;
	(*tiles_dest)->frame = (*tiles_player)->frame;
	(*tiles_dest)->var = (*tiles_player)->var;
	free((*tiles_dest)->path);
	(*tiles_dest)->path = (*tiles_player)->path;
	(*tiles_player)->type = '0';
	(*tiles_player)->frame = 0;
	(*tiles_player)->var = 0;
	(*tiles_player)->path = ft_strdup(BASIC_TILES);
	if ((*tiles_player)->path == NULL)
		return (-1);
	return (0);
}

static int	ft_moving(t_maps **maps, int pos_x, int pos_y, int keycode)
{
	t_tiles	*tiles_player;
	t_tiles	*tiles_dest;

	tiles_player = (*maps)->tiles;
	tiles_dest = (*maps)->tiles;
	while (tiles_player->x_pos != pos_x || tiles_player->y_pos != pos_y)
		tiles_player = tiles_player->next;
	if (keycode == 'w')
		pos_y -= 1;
	else if (keycode == 'a')
		pos_x -= 1;
	else if (keycode == 's')
		pos_y += 1;
	else if (keycode == 'd')
		pos_x += 1;
	while (tiles_dest->x_pos != pos_x || tiles_dest->y_pos != pos_y)
		tiles_dest = tiles_dest->next;
	return (ft_swap(&tiles_player, &tiles_dest));
}

// return value of ft_move :
// -3 = error, -2 = ennemy, -1 = wall, 0 = space, 1 = coin, 2 = exit

int	ft_move(t_maps **maps, int keycode)
{
	int	pos[2];
	int	res;

	ft_get_player_pos(maps, &pos);
	res = ft_can_move(maps, pos[0], pos[1], keycode);
	if (res == -2)
	{
		(*maps)->status_game = 1;
		(*maps)->n_frame = 0;
	}
	else if (res == 1)
		(*maps)->collectible_count += 1;
	else if (res == 2)
	{
		(*maps)->status_game = 2;
		(*maps)->n_frame = 0;
	}
	if (res >= 0 && res <= 2)
	{
		(*maps)->movements += 1;
		if (ft_moving(maps, pos[0], pos[1], keycode) != 0)
			return (-3);
	}
	return (res);
}
