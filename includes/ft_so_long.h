/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 12:03:37 by cmaginot         ###   ########.fr       */
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
# define COLOR_TEXT 15945773
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
# define PLAYER_GAME_OVER "./data/player/cat_game_over_"
# define PLAYER_EXIT_MAX_FRAME 12
# define PLAYER_EXIT "./data/player/cat_exit_"
# define PLAYER_WIN_MAX_FRAME 6
# define PLAYER_WIN "./data/player/cat_win_"
# define EXIT "./data/exit.xpm"
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

typedef struct s_enemies
{
	int					x_pos;
	int					y_pos;
	int					x_last_pos;
	int					y_last_pos;
	struct s_enemies	*next;
}						t_enemies;

typedef struct s_maps
{
	char				**map;
	int					x_lenght;
	int					y_lenght;
	int					movements;
	int					collectible_count;
	int					collectible_total;
	int					status_game;
	int					n_frame;
	void				*mlx;
	void				*mlx_win;
	struct s_tiles		*tiles;
	struct s_enemies	*enemies;
}						t_maps;

/* ************************************************************************** */
/*                                  FONCTION                                  */
/* ************************************************************************** */
int		main(int argc, const char **argv);
t_maps	*ft_init_maps(void);
void	ft_free_maps(t_maps **maps);
void	ft_get_map(char ***map, const char *path);
void	ft_free_map(char ***map);
char	*ft_check_map_validity(const char **map);
int		ft_cont_total_collectible(char **map);
void	ft_get_size_map(t_maps **maps);
void	ft_init_tiles(t_maps **maps);
void	ft_free_tiles(t_tiles **tiles);
void	ft_init_enemies(t_maps **maps);
void	ft_free_enemies(t_enemies **enemies);
char	*ft_get_path(t_maps *maps, t_tiles *tiles);
char	*ft_select_wall(t_maps *maps, t_tiles *tiles);
int		ft_draw_scene(t_maps **maps);
int		ft_update_frame(t_maps **maps);
int		ft_move_enemies(t_maps **maps);
int		ft_move(t_maps **maps, int keycode);
void	ft_success(void);
void	ft_error(char *str);
/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
