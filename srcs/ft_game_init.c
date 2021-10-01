/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/10/01 16:49:59 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

char	*ft_game_init(t_maps *maps)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*scene;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_SPRITE * maps->x_lenght, \
									SIZE_SPRITE * maps->y_lenght, "so_long");
	if (ft_draw_scene(mlx, &scene, maps) != 0)
		return ("drawing error");
	ft_put_images(scene, mlx, mlx_win, maps);
	free (scene);
	mlx_loop(mlx);
	return ("");
}
