/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_images_management.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/29 21:20:17 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_fill_img(void *mlx, t_data *scene, char *path)
{
	int		img_width;
	int		img_height;

	img_width = SIZE_SPRITE;
	img_height = SIZE_SPRITE;
	scene->img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
}

void	ft_put_images(t_data *scene, void *mlx, void *mlx_win, int size_map[2])
{
	int	pos[2];

	pos[1] = 0;
	while (pos[1] < size_map[1])
	{
		pos[0] = 0;
		while (pos[0] < size_map[0])
		{
			mlx_put_image_to_window(mlx, mlx_win, \
				scene[pos[0] + pos[1] * size_map[0]].img, \
				SIZE_SPRITE * pos[0], SIZE_SPRITE * pos[1]);
			pos[0] += 1;
		}
		pos[1] += 1;
	}
}
