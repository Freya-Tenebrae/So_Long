/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_draw_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/10/01 17:03:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_draw_border_wall(void *mlx, t_data **scene, t_maps *maps, \
								int pos[2])
{
	if (pos[1] == maps->y_lenght - 1)
		ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
			maps->x_lenght]), WALL_S);
	else if (pos[0] == 0)
		ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
			maps->x_lenght]), WALL_W);
	else if (pos[0] == maps->x_lenght - 1)
		ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
			maps->x_lenght]), WALL_E);
	else if (pos[1] == 0)
	{
		if ((pos[0] % 2 == 1))
			ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
				maps->x_lenght]), WALL_N);
		else if ((pos[0] % 6 == 2))
			ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
				maps->x_lenght]), WALL_N_V1);
		else
			ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
				maps->x_lenght]), WALL_N_V0);
	}
	return (0);
}

static int	ft_draw_inner_wall(void *mlx, t_data **scene, t_maps *maps, \
								int pos[2])
{
	ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
		maps->x_lenght]), WALL_00);
	return (0);
}

int	ft_draw_wall(void *mlx, t_data **scene, t_maps *maps, int pos[2])
{
	if (pos[0] == 0 || pos[0] == maps->x_lenght - 1 || \
		pos[1] == 0 || pos[1] == maps->y_lenght - 1)
		return (ft_draw_border_wall(mlx, scene, maps, pos));
	else
		return (ft_draw_inner_wall(mlx, scene, maps, pos));
}
