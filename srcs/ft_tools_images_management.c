/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_images_management.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 05:35:46 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	ft_fill_img(void *mlx, t_tiles **tiles)
{
	int		img_width;
	int		img_height;

	img_width = SIZE_SPRITE;
	img_height = SIZE_SPRITE;
	(*tiles)->img = mlx_xpm_file_to_image(mlx, (*tiles)->path, &img_width, \
											&img_height);
}

int	ft_draw_scene(void *mlx, t_maps *maps, t_tiles **tiles)
{
	t_tiles	**tiles_ptr;

	tiles_ptr = tiles;
	while (*tiles_ptr != NULL)
	{
		ft_fill_img(mlx, tiles_ptr);
		mlx_put_image_to_window(mlx, mlx_win, (*tiles)->img, \
								SIZE_SPRITE * (*tiles)->x_pos, \
								SIZE_SPRITE * (*tiles)->y_pos);
		*tiles_ptr = (*tiles_ptr)->next;
	}
	return (0);
}
