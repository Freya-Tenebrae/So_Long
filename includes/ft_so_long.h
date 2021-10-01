/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/01 18:52:21 by cmaginot         ###   ########.fr       */
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
# define WALL_TO_DEFINE_START "./data/type_1/wall/wall_"
# define WALL_TO_DEFINE_END ".xpm"
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
char	*ft_select_wall(t_maps *maps, int pos[2]);
/* ************************************************************************** */
/*                                   BONUS                                    */
/* ************************************************************************** */
#endif
