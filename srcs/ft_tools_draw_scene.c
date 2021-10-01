/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_draw_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/10/01 17:03:30 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_draw_empty_space(void *mlx, t_data **scene, t_maps *maps, \
								int pos[2])
{
	ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
		maps->x_lenght]), BASIC_TILES);
	return (0);
}

static int	ft_draw_one_square(void *mlx, t_data **scene, t_maps *maps, \
								int pos[2])
{
	if (maps->map[pos[1]][pos[0]] == '1')
		return (ft_draw_wall(mlx, scene, maps, pos));
	else if (maps->map[pos[1]][pos[0]] == 'P')
		return (ft_draw_player(mlx, scene, maps, pos));
	else if (maps->map[pos[1]][pos[0]] == 'C')
		return (ft_draw_collectible(mlx, scene, maps, pos));
	else if (maps->map[pos[1]][pos[0]] == 'E')
		return (ft_draw_exit(mlx, scene, maps, pos));
	else if (maps->map[pos[1]][pos[0]] == 'X')
		return (ft_draw_exit(mlx, scene, maps, pos));
	else
		return (ft_draw_empty_space(mlx, scene, maps, pos));
}

int	ft_draw_scene(void *mlx, t_data **scene, t_maps *maps)
{
	int		pos[2];

	(*scene) = malloc(sizeof(t_data) * (maps->x_lenght * maps->y_lenght));
	if (!(*scene))
		return (-1);
	pos[1] = 0;
	while (pos[1] < maps->y_lenght)
	{
		pos[0] = 0;
		while (pos[0] < maps->x_lenght)
		{
			if (ft_draw_one_square(mlx, scene, maps, pos) != 0)
				return (-1);
			pos[0] += 1;
		}
		pos[1] += 1;
	}
	return (0);
}
