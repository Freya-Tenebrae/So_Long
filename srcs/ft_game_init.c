/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/29 18:06:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_fill_img(void *mlx, t_data *img)
{
	int i;
	int j;

	img->img = mlx_new_image(mlx, SIZE_SPRITE, SIZE_SPRITE);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
								&(img->line_length), &(img->endian));
	i = 0;
	while (i < SIZE_SPRITE)
	{
		j = 0;
		while (j < SIZE_SPRITE)
		{
			if (i < 4 || i >= SIZE_SPRITE - 4 || j < 4 || \
				j >= SIZE_SPRITE - 4)
				my_mlx_pixel_put(img, i, j, 0x00FF0000);
			else
				my_mlx_pixel_put(img, i, j, 0xFF000000);
			j += 1;
		}
		i += 1;
	}
}

char	*ft_game_init(char **map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img[4];

	ft_putnbr(SIZE_SPRITE);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_SPRITE * 24, SIZE_SPRITE * 12, "so_long");

	ft_fill_img(mlx, &(img[0]));
	ft_fill_img(mlx, &(img[1]));
	ft_fill_img(mlx, &(img[2]));
	ft_fill_img(mlx, &(img[3]));
	mlx_loop(mlx);

	(void)map;
	return ("");
}
