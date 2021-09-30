/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/09/30 17:50:50 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

char	*ft_game_init(t_maps *maps)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*scene;
	int		size_map[2];
	int		pos[2];

	mlx = mlx_init();
	size_map[0] = maps->x_lenght;
	size_map[1] = maps->y_lenght;
	mlx_win = mlx_new_window(mlx, SIZE_SPRITE * size_map[0], \
									SIZE_SPRITE * size_map[1], "so_long");
	scene = malloc(sizeof(t_data) * (size_map[0] * size_map[1]));
	if (!scene)
		return ("malloc error");
	pos[1] = 0;
	while (pos[1] < size_map[1])
	{
		pos[0] = 0;
		while (pos[0] < size_map[0])
		{
			if (pos[1] == size_map[1] - 1)
				ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
					"./data/type_1/wall_s.xpm");
			else if ((pos[1] == size_map[1] - 2) && ((pos[0] == 0) || \
													pos[0] == size_map[0] - 1))
				ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
					"./data/type_1/wall_n_basic.xpm");
			else if (pos[0] == 0)
				ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
					"./data/type_1/wall_w.xpm");
			else if (pos[0] == size_map[0] - 1)
				ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
					"./data/type_1/wall_e.xpm");
			else if (pos[1] == 0)
			{
				if ((pos[0] % 2 == 1))
					ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
						"./data/type_1/wall_n_basic.xpm");
				else if ((pos[0] % 6 == 2))
					ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
						"./data/type_1/wall_n_bricked_window.xpm");
				else
					ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
						"./data/type_1/wall_n_window.xpm");
			}
			else
				ft_fill_img(mlx, &(scene[pos[0] + pos[1] * size_map[0]]), \
					"./data/type_1/basic_tile.xpm");
			pos[0] += 1;
		}
		pos[1] += 1;
	}
	ft_put_images(scene, mlx, mlx_win, size_map);
	mlx_loop(mlx);
	return ("");
}
