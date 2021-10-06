/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 07:13:23 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	ft_parsing(t_maps **maps, const char *map_path)
{
	char	*result;

	ft_get_map(&((*maps)->map), map_path);
	result = ft_check_map_validity((const char **)(*maps)->map);
	if (ft_strcmp(result, "") != 0)
	{
		ft_free_maps(maps);
		ft_error(result);
	}
	ft_get_size_map(maps);
	ft_init_tiles(maps);
	if ((*maps)->tiles == NULL)
	{
		ft_free_maps(maps);
		ft_error("malloc error");
	}
}

int	main(int argc, const char **argv)
{
	t_maps	*maps;
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
		ft_error("incorect numbers of arguments");
	maps = ft_init_maps();
	if (!maps)
		ft_error("malloc error");
	ft_parsing(&maps, argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_SPRITE * maps->x_lenght, \
								SIZE_SPRITE * maps->y_lenght, "so_long");
	if (ft_draw_scene(mlx, mlx_win, &maps) != 0)
	{
		ft_free_maps(&maps);
		ft_error("drawing error");
	}
	mlx_loop(mlx);
	ft_free_maps(&maps);
	ft_success();
}
