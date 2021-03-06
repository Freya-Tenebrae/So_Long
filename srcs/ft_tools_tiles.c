/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 12:05:17 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static t_tiles	*ft_init_tile_part_2(t_maps *maps, t_tiles *tiles)
{
	char		*path;

	tiles->frame = 1;
	path = ft_get_path(maps, tiles);
	if (path != NULL)
	{
		tiles->path = path;
		tiles->img = NULL;
		tiles->next = NULL;
		return (tiles);
	}
	free(tiles);
	return (NULL);
}

static t_tiles	*ft_init_tile(t_maps *maps, int pos[2])
{
	t_tiles		*tiles;
	static int	var;

	if (!var)
		var = 0;
	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
		return (NULL);
	tiles->x_pos = pos[0];
	tiles->y_pos = pos[1];
	if (maps->map[tiles->y_pos][tiles->x_pos] == 'x')
		tiles->type = '0';
	else
		tiles->type = maps->map[tiles->y_pos][tiles->x_pos];
	if (tiles->type == 'C')
		tiles->var = 1 + var++ % COLLECTIBLE_ALT_NBR;
	else if (tiles->type == 'X')
		tiles->var = 1 + var++ % ENEMIES_ALT_NBR;
	else
		tiles->var = 1;
	return (ft_init_tile_part_2(maps, tiles));
}

void	ft_free_tiles(t_tiles **tiles)
{
	t_tiles	*tiles_ptr;

	tiles_ptr = *tiles;
	while (tiles_ptr != NULL)
	{
		tiles_ptr = tiles_ptr->next;
		if ((*tiles)->path != NULL)
			free((*tiles)->path);
		free(*tiles);
		*tiles = tiles_ptr;
	}	
}

static int	ft_call_init_tiles(t_maps **maps, t_tiles **tiles_ptr, int pos[2])
{
	t_tiles		*tiles_new;

	tiles_new = ft_init_tile(*maps, pos);
	if (tiles_new == NULL)
	{
		ft_free_maps(maps);
		return (-1);
	}
	if (*tiles_ptr == NULL)
	{
		(*maps)->tiles = tiles_new;
		*tiles_ptr = (*maps)->tiles;
	}
	else
	{
		(*tiles_ptr)->next = tiles_new;
		*tiles_ptr = (*tiles_ptr)->next;
	}
	return (0);
}

void	ft_init_tiles(t_maps **maps)
{
	t_tiles	*tiles_ptr;
	int		pos[2];

	tiles_ptr = NULL;
	pos[1] = 0;
	while (pos[1] < (*maps)->y_lenght)
	{
		pos[0] = 0;
		while (pos[0] < (*maps)->x_lenght)
		{
			if (ft_call_init_tiles(maps, &tiles_ptr, pos) == -1)
				return ;
			pos[0] += 1;
		}
		pos[1] += 1;
	}
}
