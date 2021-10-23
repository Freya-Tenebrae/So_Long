/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_update_frame.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 09:30:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_update_frame_player(t_maps *maps, t_tiles *tiles_ptr)
{
	if (maps->status_game == 0 || maps->status_game == 1)
		tiles_ptr->frame = (maps->n_frame % PLAYER_MAX_FRAME) + 1;
	else if (maps->status_game == 2)
	{
		tiles_ptr->frame = (maps->n_frame % PLAYER_EXIT_MAX_FRAME) + 1;
		if (maps->n_frame >= 12)
		{
			maps->status_game = 3;
			maps->n_frame = 0;
		}
	}
	else
		tiles_ptr->frame = (maps->n_frame % PLAYER_WIN_MAX_FRAME) + 1;
	free(tiles_ptr->path);
	tiles_ptr->path = ft_get_path(maps, tiles_ptr);
	if (tiles_ptr->path == NULL)
		return (-1);
	return (0);
}

static int	ft_update_frame_collectible(t_maps *maps, t_tiles *tiles_ptr)
{
	tiles_ptr->frame = (maps->n_frame % COLLECTIBLE_MAX_FRAME) + 1;
	free(tiles_ptr->path);
	tiles_ptr->path = ft_get_path(maps, tiles_ptr);
	if (tiles_ptr->path == NULL)
		return (-1);
	return (0);
}

static int	ft_update_frame_enemy(t_maps *maps, t_tiles *tiles_ptr)
{
	tiles_ptr->frame = (maps->n_frame % ENEMIES_MAX_FRAME) + 1;
	free(tiles_ptr->path);
	tiles_ptr->path = ft_get_path(maps, tiles_ptr);
	if (tiles_ptr->path == NULL)
		return (-1);
	return (0);
}

int	ft_update_frame(t_maps **maps)
{
	t_tiles		*tiles_ptr;

	if ((*maps)->n_frame >= 24)
		(*maps)->n_frame = 0;
	tiles_ptr = (*maps)->tiles;
	while (tiles_ptr != NULL)
	{
		if (tiles_ptr->type == 'P')
			if (ft_update_frame_player((*maps), tiles_ptr) != 0)
				return (-1);
		if (tiles_ptr->type == 'C')
			if (ft_update_frame_collectible((*maps), tiles_ptr) != 0)
				return (-1);
		if (tiles_ptr->type == 'X')
			if (ft_update_frame_enemy((*maps), tiles_ptr) != 0)
				return (-1);
		tiles_ptr = tiles_ptr->next;
	}
	(*maps)->n_frame += 1;
	return (0);
}
