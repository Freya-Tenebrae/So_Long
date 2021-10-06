/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_get_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/10/06 07:16:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static char	*ft_select_border_wall(t_maps *maps, t_tiles *tiles)
{
	if (tiles->y_pos == maps->y_lenght - 1)
	{
		if (tiles->x_pos == 0 || tiles->x_pos == maps->x_lenght - 1)
			return (strdup(WALL_S));
		else
			return (ft_select_wall(maps, tiles));
	}
	else if (tiles->x_pos == 0)
		return (strdup(WALL_W));
	else if (tiles->x_pos == maps->x_lenght - 1)
		return (strdup(WALL_E));
	else if (tiles->y_pos == 0)
	{
		if ((tiles->x_pos % 2 == 1))
			return (strdup(WALL_N));
		else if ((tiles->x_pos % 6 == 2))
			return (strdup(WALL_N_V1));
		else
			return (strdup(WALL_N_V0));
	}
	return (0);
}


static char	*get_str_path_wall(t_maps *maps, t_tiles *tiles)
{
	if (tiles->x_pos == 0 || tiles->x_pos == maps->x_lenght - 1 || \
		tiles->y_pos == 0 || tiles->y_pos == maps->y_lenght - 1)
		return (ft_select_border_wall(maps, tiles));
	else
		return (ft_select_wall(maps, tiles));
}

static char	*get_str_path(t_tiles *tiles, char *first_part_path)
{
	char	*str;
	char	*str_joined;

	if (tiles->type == 'C' || tiles->type == 'X')
	{
		str = ft_itoa(tiles->var);
		if (str == NULL)
			return (NULL);
		str_joined = ft_strjoin(first_part_path, str);
		free(str);
		if (str_joined == NULL)
			return (NULL);
		str = ft_strjoin(str_joined, "_");
		free(str_joined);
	}
	else
		str = strdup(first_part_path);
	if (str == NULL)
			return (NULL);
	str_joined = ft_strjoin(str, XPM);
	free(str);
	return (str_joined);
}

char	*ft_get_path(t_maps *maps, t_tiles *tiles)
{
	if (tiles->type == '1')
		return (get_str_path_wall(maps, tiles));
	else if (tiles->type == 'P')
		return (get_str_path(tiles, PLAYER_IDDLE));
	else if (tiles->type == 'C')
		return (get_str_path(tiles, COLLECTIBLE));
	else if (tiles->type == 'E')
		return (get_str_path(tiles, EXIT));
	else if (tiles->type == 'X')
		return (get_str_path(tiles, ENEMIES));
	else
		return (ft_strdup(BASIC_TILES));
}