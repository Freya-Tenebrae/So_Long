/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_images_management.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 10:15:41 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

/* need to put some error management here*/

static void	ft_fill_img(void *mlx, t_tiles **tiles)
{
	int		img_width;
	int		img_height;

	img_width = SIZE_SPRITE;
	img_height = SIZE_SPRITE;
	(*tiles)->img = mlx_xpm_file_to_image(mlx, (*tiles)->path, &img_width, \
											&img_height);
}

static int	ft_putnbr_to_win(t_maps **maps)
{
	char	*char_to_put;

	char_to_put = ft_itoa((*maps)->movements);
	if (char_to_put == NULL)
		return (-1);
	mlx_string_put((*maps)->mlx, (*maps)->mlx_win, 20, SIZE_SPRITE / 2, \
					mlx_get_color_value((*maps)->mlx, COLOR_TEXT), \
					char_to_put);
	free (char_to_put);
	return (0);
}

int	ft_draw_scene(t_maps **maps)
{
	t_tiles	*tiles_ptr;

	tiles_ptr = (*maps)->tiles;
	while (tiles_ptr != NULL)
	{
		ft_fill_img((*maps)->mlx, &tiles_ptr);
		mlx_put_image_to_window((*maps)->mlx, (*maps)->mlx_win, \
								tiles_ptr->img, \
								SIZE_SPRITE * tiles_ptr->x_pos, \
								SIZE_SPRITE * tiles_ptr->y_pos);
		mlx_destroy_image((*maps)->mlx, tiles_ptr->img);
		tiles_ptr = tiles_ptr->next;
	}
	if ((*maps)->status_game == 1)
		mlx_string_put((*maps)->mlx, (*maps)->mlx_win, \
						(SIZE_SPRITE * (*maps)->x_lenght) / 2, \
						SIZE_SPRITE * ((*maps)->y_lenght / 2), \
						mlx_get_color_value((*maps)->mlx, COLOR_TEXT), \
						"GAME OVER");
	else if ((*maps)->status_game == 2 || (*maps)->status_game == 3)
		mlx_string_put((*maps)->mlx, (*maps)->mlx_win, \
						(SIZE_SPRITE * (*maps)->x_lenght) / 2, \
						SIZE_SPRITE * ((*maps)->y_lenght / 2), \
						mlx_get_color_value((*maps)->mlx, COLOR_TEXT), "WIN");
	return (ft_putnbr_to_win(maps));
}
