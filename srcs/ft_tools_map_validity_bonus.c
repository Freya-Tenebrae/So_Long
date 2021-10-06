/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_map_validity_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 03:32:29 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static char	ft_check_map_validity_rectangle(const char **map)
{
	int	width_map;
	int	n_line;

	width_map = (int)ft_strlen(map[0]);
	if (width_map < 3)
		return("the map is too small");
	n_line = 1;
	while (map[n_line] != NULL)
	{
		if ((int)ft_strlen(map[n_line]) != width_map)
			return("the map isn't rectangular");
		n_line += 1;
	}
	if (n_line < 3)
		return("the map is too small");
}

static char	ft_check_map_validity_souronding(const char **map)
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
					return("the map isn't sourounded by wall");
			}
			n_char += 1;
		}
		n_line += 1;
	}
}

static char	ft_check_map_validity_all_actor_are_valid(const char **map)
{
	int	n_line;
	int	n_char;

	n_line = 0;
	while (map[n_line] != NULL)
	{
		n_char = 0;
		while (map[n_line][n_char] != '\0')
		{
			if (ft_strchr("01PCEXx", map[n_line][n_char]) == NULL)
				return("an actor (pickup, exit, player, ...) isn't valid");
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

char	*ft_check_map_validity(const char **map)
{
	char	*result;

	if (map == NULL)
		return("the map is empty");
	result = ft_check_map_validity_rectangle(map);
	if (ft_strcmp(result, "") != 0)
		return (result);
	result = ft_check_map_validity_souronding(map);
	if (ft_strcmp(result, "") != 0)
		return (result);
	result = ft_check_map_validity_all_actor_are_valid(map);
	if (ft_strcmp(result, "") != 0)
		return (result);
	if (ft_check_map_validity_actor_present(map, "P") != 0)
		return("a mendatory actor 'Player' isn't present");
	if (ft_check_map_validity_actor_present(map, "E") != 0)
		return("a mendatory actor 'Exit' isn't present");
	if (ft_check_map_validity_actor_present(map, "C") != 0)
		return("a mendatory actor 'Collectible' isn't present");
}
