/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_map_validity_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/24 09:15:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	ft_check_map_validity_rectangle_and_type_tileset(const char **map)
{
	int	width_map;
	int	n_line;

	if (ft_strcmp(map[0], "type_1") != 0 && \
		ft_strcmp(map[0], "type_1") != 0 && \
		ft_strcmp(map[0], "type_1") != 0)
		ft_error("the tileset present on this map isn't valid");
	width_map = (int)ft_strlen(map[1]);
	if (width_map < 3)
		ft_error("the map is too small");
	n_line = 2;
	while (map[n_line] != NULL)
	{
		if ((int)ft_strlen(map[n_line]) != width_map)
			ft_error("the map isn't rectangular");
		n_line += 1;
	}
	if (n_line < 4)
		ft_error("the map is too small");
}

static void	ft_check_map_validity_souronding(const char **map)
{
	int	width_map;
	int	n_line;
	int	n_char;

	width_map = (int)ft_strlen(map[1]);
	n_line = 1;
	while (map[n_line] != NULL)
	{
		n_char = 0;
		while (map[n_line][n_char] != '\0')
		{
			if (n_line == 0 || map[n_line + 1] == NULL || n_char == 0 || \
				n_char == width_map - 1)
			{
				if (map[n_line][n_char] != '1')
					ft_error("the map isn't sourounded by wall");
			}
			n_char += 1;
		}
		n_line += 1;
	}
}

static void	ft_check_map_validity_all_actor_are_valid(const char **map)
{
	int	n_line;
	int	n_char;

	n_line = 1;
	while (map[n_line] != NULL)
	{
		n_char = 0;
		while (map[n_line][n_char] != '\0')
		{
			if (ft_strchr("01PCEXxKDH", map[n_line][n_char]) == NULL)
				ft_error("an actor (pickup, exit, player, ...) isn't valid");
			n_char += 1;
		}
		n_line += 1;
	}
}

static int	ft_check_map_validity_actor_present(const char **map, \
												const char *actor)
{
	int	n_line;
	int	n_char;

	n_line = 1;
	while (map[n_line] != NULL)
	{
		n_char = 0;
		while (map[n_line][n_char] != '\0')
		{
			if (ft_strchr(actor, map[n_line][n_char]) != NULL)
				return (0);
			n_char += 1;
		}
		n_line += 1;
	}
	return (-1);
}

void	ft_check_map_validity(const char **map)
{
	if (map == NULL)
		ft_error("the map is empty");
	ft_check_map_validity_rectangle_and_type_tileset(map);
	ft_check_map_validity_souronding(map);
	ft_check_map_validity_all_actor_are_valid(map);
	if (ft_check_map_validity_actor_present(map, "P") != 0)
		ft_error("a mendatory actor 'Player' isn't present");
	if (ft_check_map_validity_actor_present(map, "E") != 0)
		ft_error("a mendatory actor 'Exit' isn't present");
}
