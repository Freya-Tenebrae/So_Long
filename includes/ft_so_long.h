/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/29 19:35:39 by cmaginot         ###   ########.fr       */
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
char	*ft_game_init(char **map);
/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
void	ft_error(char *str);
void	ft_get_map(char ***map, const char *path);
void	ft_free_map(char ***map);
void	ft_fill_img(void *mlx, t_data *img, char *path);
void	ft_put_images(t_data *img, void *mlx, void *mlx_win, int size_map[2]);
/* ************************************************************************** */
/*                                   BONUS                                    */
/* ************************************************************************** */
t_maps	*ft_init_maps(void);
char	*ft_game_init_bonus(t_maps *maps);
void	ft_free_maps(t_maps **maps);
#endif
