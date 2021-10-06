/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 05:20:45 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static t_tiles	*ft_init_tile(t_maps *maps, char type, int var, int pos[2])
{
	t_tiles	*tiles;
	char	*path;

	tiles = malloc(sizeof(t_tiles));
	if (!tiles)
		return (NULL);
	tiles->type = type;
	if (type == 'C')
		tiles->var = var % COLLECTIBLE_ALT_NBR;
	else if (type == 'X')
		tiles->var = var % ENEMIES_ALT_NBR;
	else
		tile->var = 0;
	tiles->frame = 0;
	tiles->x_pos = pos[0];
	tiles->y_pos = pos[1];
	path = ft_get_path(maps, pos, tiles->type, tiles->var);
	if (path == NULL)
		return (NULL);
	tiles->path = path;
	tiles->img = NULL;
	tiles->next = NULL;
	return (tiles);
}

void	ft_free_tiles(t_tiles **tiles)
{
	t_tiles	*tiles_ptr;

	tiles_ptr = *tiles;
	while (tiles_ptr != NULL)
	{
		tiles_ptr = tiles_ptr->next;
		if (tiles->path != NULL)
			free(tiles->path);
		free(*tiles);
		*tiles = tiles_ptr;
	}	
}

static int	*ft_call_init_tiles(t_maps *maps, t_tiles **tiles, \
									t_tiles **tiles_ptr, int pos[])
{
	t_tiles		*tiles_new;
	static int	var;

	if (!var)
		var = 0;
	tiles_new = ft_init_tile(maps, maps->map[pos[1]][pos[0]] , var, pos);
	if (tiles_new == NULL)
	{
		if (*tiles_ptr != NULL)
			ft_free_tiles(tiles);
		return (-1);
	}
	if (maps->map[pos[1]][pos[0]] == 'C' || maps->map[pos[1]][pos[0]] == 'X')
		var += 1;
	if (*tiles_ptr == NULL)
	{
		*tiles = tiles_new()
		*tiles_ptr = *tiles;
	}
	else
	{
		(*tiles_ptr)->next = tiles_new;
		*tiles_ptr = (*tiles_ptr)->next;
	}
}

t_tiles	*ft_init_tiles(t_maps *maps)
{
	t_tiles	*tiles;
	t_tiles	*tiles_ptr;
	int		pos[2];

	tiles_ptr == NULL;
	pos[1] = 0;
	while (pos[1] < maps->y_lenght)
	{
		pos[0] = 0;
		while (pos[0] < maps->x_lenght)
		{
			if (ft_call_init_tiles(map, &tiles, &tiles_ptr, pos) == -1)
				return (-1);
			pos[0] += 1;
		}
		pos[1] += 1;
	}
	return (0);
}
