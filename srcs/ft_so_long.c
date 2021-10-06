/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 06:26:45 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static char	*ft_game_init(t_maps **maps)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SIZE_SPRITE * (*maps)->x_lenght, \
									SIZE_SPRITE * (*maps)->y_lenght, "so_long");
	if (ft_draw_scene(mlx, maps) != 0)
		return ("drawing error");
	mlx_loop(mlx);
	return ("");
}

static void	ft_parsing(t_maps **maps)
{
	char	*result;

	result = ft_check_map_validity((const char **)(*maps)->map);
	if (ft_strcmp(result, "") != 0)
	{
		ft_free_maps(maps);
		ft_error(result);
	}
	ft_init_tiles(&maps);
	if ((*maps)->tiles == NULL)
	{
		ft_free_maps(maps);
		ft_error("malloc error");
	}
	ft_get_size_map(maps);
}

int	main(int argc, const char **argv)
{
	t_maps	*maps;
	char	*result;

	if (argc != 2)
		ft_error("incorect numbers of arguments");
	maps = ft_init_maps();
	if (!maps)
		ft_error("malloc error");
	maps->map = NULL;
	ft_get_map(&(maps->map), argv[1]);
	ft_parsing(&maps);
	result = ft_game_init(&maps);
	ft_free_maps(&maps);
	if (ft_strcmp(result, "") == 0)
		ft_success();
	ft_error(result);
	return (0);
}
