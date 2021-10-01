/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_images_management.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/01 15:51:19 by cmaginot         ###   ########.fr       */
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

void	ft_put_images(t_data *scene, void *mlx, void *mlx_win, t_maps *maps)
{
	int	pos[2];

	pos[1] = 0;
	while (pos[1] < maps->y_lenght)
	{
		pos[0] = 0;
		while (pos[0] < maps->x_lenght)
		{
			mlx_put_image_to_window(mlx, mlx_win, \
				scene[pos[0] + pos[1] * maps->x_lenght].img, \
				SIZE_SPRITE * pos[0], SIZE_SPRITE * pos[1]);
			pos[0] += 1;
		}
		pos[1] += 1;
	}
}
