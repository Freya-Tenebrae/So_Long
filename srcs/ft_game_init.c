/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/28 17:49:03 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

char	*ft_game_init(char **map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);


	int i = 0;
	while (i <= 500)
	{
		int j = 0;
		while (j <= 500)
		{
			if (i < 10 || i >= 490 || j < 10 || j >= 490)
				my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			else
				my_mlx_pixel_put(&img, i, j, 0xFF000000);
			j += 1;
		}
		i += 1;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 350, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 350);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 350, 350);
	mlx_loop(mlx);
	(void)map;
	return ("");
}
