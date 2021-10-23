/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 06:21:20 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int ft_cont_total_collectible(char **map)
{
	int	n_line;
	int	n_char;
	int	n_collectible;

	n_line = 0;
	n_collectible = 0;
	while (map[n_line] != NULL)
	{
		n_char = 0;
		while (map[n_line][n_char] != '\0')
		{
			if (ft_strchr("C", map[n_line][n_char]) != NULL)
				n_collectible += 1;
			n_char += 1;
		}
		n_line += 1;
	}
	return (n_collectible);
}

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
	(*maps)->colectible_total == ft_cont_total_collectible((*maps)->map);
	ft_init_tiles(maps);
	if ((*maps)->tiles == NULL)
	{
		ft_free_maps(maps);
		ft_error("malloc error");
	}
}

static void ft_close_app(t_maps **maps)
{
	ft_free_maps(maps);
	ft_success();
}

static int	ft_key_hook(int keycode, t_maps **maps)
{
	if (keycode == 65307)
		ft_close_app(maps);
	else if (keycode == 'w' || keycode == 'a' || \
			keycode == 's' || keycode == 'd')
	{
		ft_move(maps, keycode);
		ft_putstr_fd("Movements : ", 1);
		ft_putnbr_fd((*maps)->movements, 1);
		ft_putstr_fd(".\n", 1);
	}
	if (ft_draw_scene((*maps)->mlx, (*maps)->mlx_win, maps) != 0)
	{
		ft_free_maps(maps);
		ft_error("drawing error");
	}
	return(0);
}

//static void	ft_render_next_frame(t_maps **maps)
//{
	
//}

int	main(int argc, const char **argv)
{
	t_maps	*maps;

	if (argc != 2)
		ft_error("incorrect numbers of arguments");
	maps = ft_init_maps();
	if (!maps)
		ft_error("malloc error");
	ft_parsing(&maps, argv[1]);
	maps->mlx = mlx_init();
	maps->mlx_win = mlx_new_window(maps->mlx, SIZE_SPRITE * maps->x_lenght, \
								SIZE_SPRITE * maps->y_lenght, "so_long");
	if (ft_draw_scene(maps->mlx, maps->mlx_win, &maps) != 0)
	{
		ft_free_maps(&maps);
		ft_error("drawing error");
	}
	mlx_key_hook(maps->mlx_win, ft_key_hook, &maps);
	//mlx_loop_hook(maps->mlx, ft_render_next_frame, &maps);
	mlx_loop(maps->mlx);
	ft_free_maps(&maps);
	ft_success();
	return (0);
}
