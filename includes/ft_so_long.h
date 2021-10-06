v/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 05:00:20 by cmaginot         ###   ########.fr       */
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
# define BASIC_TILES "./data/basic_tile.xpm"
# define WALL_TO_DEFINE "./data/wall/wall_"
# define WALL_S "./data/wall/wall_s.xpm"
# define WALL_E "./data/wall/wall_e.xpm"
# define WALL_W "./data/wall/wall_w.xpm"
# define WALL_N "./data/wall/wall_n_basic.xpm"
# define WALL_N_V0 "./data/wall/wall_n_window.xpm"
# define WALL_N_V1 "./data/wall/wall_n_bricked_window.xpm"
# define PLAYER_MAX_FRAME 8
# define PLAYER_IDDLE "./data/player/cat_iddle_"
# define PLAYER_IDDLE_ALT "./data/player/cat_iddle_alt_"
# define PLAYER_IDDLE_PICK "./data/player/cat_iddle_pick_"
# define PLAYER_GAME_OVER "./data/player/cat_game_over_"
# define EXIT_MAX_FRAME 12
# define EXIT "./data/exit/exit.xpm"
# define EXIT_PLAYER "./data/exit/cat_exit_"
# define EXIT_WIN "./data/exit/exit_win_"
# define COLLECTIBLE_MAX_FRAME 4
# define COLLECTIBLE_ALT_NBR 4
# define COLLECTIBLE "./data/collectible/collectible_"
# define ENEMIES_MAX_FRAME 6
# define ENEMIES_ALT_NBR 2
# define ENEMIES "./data/enemies/witch_"
# define XPM ".xpm"

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_maps
{
	char				**map;
	int					x_lenght;
	int					y_lenght;
// 	int					endian;
// 	int					bits_per_pixel;
	struct s_tiles		*tiles;
}						t_maps;

typedef struct s_tiles
{
	int					x_pos;
	int					y_pos;
	char				type;
	int					var;
	int					frame;
	char				*path;
	void				*img;
	struct s_tiles		*next;
}						t_tiles;

/* ************************************************************************** */
/*                                  FONCTION                                  */
/* ************************************************************************** */
int		main(int argc, const char **argv);
void	ft_success(void);
void	ft_error(char *str);
char	*ft_get_path(t_maps *maps, int pos[2], char type, int var);
int		ft_draw_scene(void *mlx, t_maps *maps, t_tiles **tiles);
void	ft_free_map(char ***map);
void	ft_get_map(char ***map, const char *path);
char	*ft_check_map_validity(const char **map);
t_maps	*ft_init_maps(void);
void	ft_get_size_map(t_maps **maps);
void	ft_free_maps(t_maps **maps);
char	*ft_select_wall(t_maps *maps, int pos[2]);
void	ft_free_tiles(t_tiles **tiles);
t_tiles	*ft_init_tiles(t_maps *maps);
/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
