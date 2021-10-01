/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/01 17:04:22 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

/* ************************************************************************** */
/*                                   DEFINE                                   */
/* ************************************************************************** */
# define SIZE_SPRITE 64
# define BASIC_TILES "./data/type_1/basic_tile.xpm"
# define WALL_00 "./data/type_1/wall_00.xpm"
# define WALL_01 "./data/type_1/wall_01.xpm"
# define WALL_02 "./data/type_1/wall_02.xpm"
# define WALL_03 "./data/type_1/wall_03.xpm"
# define WALL_04 "./data/type_1/wall_04.xpm"
# define WALL_05 "./data/type_1/wall_05.xpm"
# define WALL_06 "./data/type_1/wall_06.xpm"
# define WALL_07 "./data/type_1/wall_07.xpm"
# define WALL_08 "./data/type_1/wall_08.xpm"
# define WALL_09 "./data/type_1/wall_09.xpm"
# define WALL_10 "./data/type_1/wall_10.xpm"
# define WALL_11 "./data/type_1/wall_11.xpm"
# define WALL_12 "./data/type_1/wall_12.xpm"
# define WALL_13 "./data/type_1/wall_13.xpm"
# define WALL_14 "./data/type_1/wall_14.xpm"
# define WALL_15 "./data/type_1/wall_15.xpm"
# define WALL_S "./data/type_1/wall_s.xpm"
# define WALL_E "./data/type_1/wall_e.xpm"
# define WALL_W "./data/type_1/wall_w.xpm"
# define WALL_N "./data/type_1/wall_n_basic.xpm"
# define WALL_N_V0 "./data/type_1/wall_n_window.xpm"
# define WALL_N_V1 "./data/type_1/wall_n_bricked_window.xpm"

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_maps
{
	char				**map;
	char				*type;
	int					x_lenght;
	int					y_lenght;
	struct s_maps		*next;
}						t_maps;
typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int		main(int argc, const char **argv);
void	ft_check_map_validity(const char **map);
char	*ft_game_init(t_maps *maps);
/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
void	ft_error(char *str);
void	ft_get_map(char ***map, const char *path);
void	ft_free_map(char ***map);
void	ft_fill_img(void *mlx, t_data *img, char *path);
void	ft_put_images(t_data *scene, void *mlx, void *mlx_win, t_maps *maps);
t_maps	*ft_init_maps(void);
void	ft_get_size_map(t_maps **maps);
void	ft_free_maps(t_maps **maps);
int		ft_draw_scene(void *mlx, t_data **scene, t_maps *maps);
int		ft_draw_wall(void *mlx, t_data **scene, t_maps *maps, int pos[2]);
int		ft_draw_player(void *mlx, t_data **scene, t_maps *maps, int pos[2]);
int		ft_draw_exit(void *mlx, t_data **scene, t_maps *maps, int pos[2]);
int		ft_draw_collectible(void *mlx, t_data **scene, t_maps *maps, \
			int pos[2]);
/* ************************************************************************** */
/*                                   BONUS                                    */
/* ************************************************************************** */
#endif
