/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_map_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/04 13:42:08 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	ft_check_map_validity_rectangle(const char **map)
{
	int	width_map;
	int	n_line;

	width_map = (int)ft_strlen(map[0]);
	if (width_map < 3)
		ft_error("the map is too small");
	n_line = 1;
	while (map[n_line] != NULL)
	{
		if ((int)ft_strlen(map[n_line]) != width_map)
			ft_error("the map isn't rectangular");
		n_line += 1;
	}
	if (n_line < 3)
		ft_error("the map is too small");
}

static void	ft_check_map_validity_souronding(const char **map)
{
	int	width_map;
	int	n_line;
	int	n_char;

	width_map = (int)ft_strlen(map[0]);
	n_line = 0;
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

	n_line = 0;
	while (map[n_line] != NULL)
	{
		n_char = 0;
		while (map[n_line][n_char] != '\0')
		{
			if (ft_strchr("01PCE", map[n_line][n_char]) == NULL)
				ft_error("an actor (pickup, exit, player, ...) isn't valid");
			n_char += 1;
		}
		n_line += 1;
	}
}

static int	ft_check_map_validity_actor_present(const char **map, \
												const char *actor)
{
	int	n_actor;
	int	n_line;
	int	n_char;

	n_actor = 0;
	n_line = 0;
	while (map[n_line] != NULL)
	{
		n_char = 0;
		while (map[n_line][n_char] != '\0')
		{
			if (ft_strchr(actor, map[n_line][n_char]) != NULL)
				n_actor += 1;
			n_char += 1;
		}
		n_line += 1;
	}
	if (n_actor == 0 || (ft_strchr(actor, 'P') != NULL && n_actor > 1))
		return (-1);
	return (0);
}

void	ft_check_map_validity(const char **map)
{
	if (map == NULL)
		ft_error("the map is empty");
	ft_check_map_validity_rectangle(map);
	ft_check_map_validity_souronding(map);
	ft_check_map_validity_all_actor_are_valid(map);
	if (ft_check_map_validity_actor_present(map, "P") != 0)
		ft_error("a mendatory actor 'Player' isn't present");
	if (ft_check_map_validity_actor_present(map, "E") != 0)
		ft_error("a mendatory actor 'Exit' isn't present");
	if (ft_check_map_validity_actor_present(map, "C") != 0)
		ft_error("a mendatory actor 'Collectible' isn't present");
}
