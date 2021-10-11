/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/11 16:06:22 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	ft_get_player_pos(t_tiles *tiles, int (*pos)[2])
{
	t_tiles	*tmp_tiles;

	tmp_tiles = tiles;
	while (tmp_tiles->type != 'P')
		tmp_tiles = tmp_tiles->next;
	(*pos)[0] = tmp_tiles->x_pos;
	(*pos)[1] = tmp_tiles->y_pos;
}

static int	ft_can_move(t_tiles *tiles, int pos[2], int keycode)
{
	t_tiles	*tmp_tiles;

	tmp_tiles = tiles;
	if (keycode == 25)
		pos[1] -= 1;
	else if (keycode == 38)
		pos[0] -= 1;
	else if (keycode == 39)
		pos[1] += 1;
	else if (keycode == 40)
		pos[0] += 1;
	while (tmp_tiles->x_pos != pos[0] && tmp_tiles->y_pos != pos[1])
		tmp_tiles = tmp_tiles->next;
	if (tmp_tiles->type == 'X')
		return (-2);
	if (tmp_tiles->type == '1')
		return (-1);
	if (tmp_tiles->type == '0')
		return (0);
	if (tmp_tiles->type == 'C')
		return (1);
	if (tmp_tiles->type == 'E')
		return (2);
}

static int	ft_swap(t_tiles *tiles_player, t_tiles *tiles_dest)
{
	tiles_dest->type = tiles_player->type;
	tiles_dest->path = tiles_player->path;
	tiles_player->type = '0';
	tiles_player->path = ft_strdup(BASIC_TILES);
	if (tiles_player->path == NULL)
		return (-1);
	return (0);
}

static int	ft_moving(t_tiles *tiles, int pos[2], int keycode)
{
	t_tiles	*tiles_player;
	t_tiles	*tiles_dest;

	tiles_player = tiles;
	tiles_dest = tiles;
	while (tiles_player->x_pos != pos[0] && tiles_player->y_pos != pos[1])
		tiles_player = tiles_player->next;
	if (keycode == 25)
		pos[1] -= 1;
	else if (keycode == 38)
		pos[0] -= 1;
	else if (keycode == 39)
		pos[1] += 1;
	else if (keycode == 40)
		pos[0] += 1;
	while (tiles_dest->x_pos != pos[0] && tiles_dest->y_pos != pos[1])
		tiles_dest = tiles_dest->next;
	return (ft_swap(tiles_player, tiles_dest));
}

// return value of ft_move :
// -3 = error, -2 = ennemy, -1 = wall, 0 = space, 1 = coin, 2 = exit

int	ft_move(t_maps *maps, int keycode)
{
	int	pos[2];
	int	res;

	ft_get_player_pos(maps->tiles, &pos);
	res = ft_can_move(maps->tiles, pos, keycode);
	ft_putstr_fd("Movements : ", 1);
	ft_putnbr_fd(maps->movements, 1);
	ft_putstr_fd(".\n", 1);
	maps->movements += 1;
	if (res >= 0 || res <= 2)
		if (ft_moving(maps->tiles, pos, keycode) != 0)
			return (-3);
	return (res);
}
