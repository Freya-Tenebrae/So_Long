/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:06:56 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/24 09:01:39 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
// # include <mlx.h>
# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_maps
{
	char			**map;
	struct s_maps	*next;
}					t_maps;
/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int		main(int argc, const char **argv);
void	ft_check_map_validity(const char **map);
/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
void	ft_error(char *str);
void	ft_get_map(char ***map, const char *path);
void	ft_free_map(char ***map);
/* ************************************************************************** */
/*                                 BONUS PART                                 */
/* ************************************************************************** */
void	ft_check_map_validity_bonus(const char **map);

#endif
