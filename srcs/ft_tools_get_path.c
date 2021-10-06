/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_get_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/10/06 05:46:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_select_border_wall(t_maps *maps, int pos[2])
{
	if (pos[1] == maps->y_lenght - 1)
	{
		if (pos[0] == 0 || pos[0] == maps->x_lenght - 1)
			return (strdup(WALL_S));
		else
			return (ft_select_wall(maps, pos))
	}
	else if (pos[0] == 0)
		return (strdup(WALL_W));
	else if (pos[0] == maps->x_lenght - 1)
		return (strdup(WALL_E));
	else if (pos[1] == 0)
	{
		if ((pos[0] % 2 == 1))
			return (strdup(WALL_N));
		else if ((pos[0] % 6 == 2))
			return (strdup(WALL_N_V1));
		else
			return (strdup(WALL_N_V0));
	}
	return (0);
}


static char	*get_str_path_wall(t_maps *maps, int pos[2])
{
	if (pos[0] == 0 || pos[0] == maps->x_lenght - 1 || \
		pos[1] == 0 || pos[1] == maps->y_lenght - 1)
		return (ft_select_border_wall(maps, pos));
	else
		return (ft_select_wall(maps, pos))
}

static char	*get_str_path(char type, char *first_part_path, int var)
{
	char	*str;
	char	*str_joined;

	if (type == C || type == X)
	{
		str = ft_itoa(var);
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

char	*ft_get_path(t_maps *maps, int pos[2], char type, int var)
{
	char *path;

	if (type == '1')
		return (get_str_path_wall(maps, pos));
	else if (type == 'P')
		return (get_str_path(type, PLAYER_IDDLE, var));
	else if (type == 'C')
		return (get_str_path(type, COLLECTIBLE, var));
	else if (type == 'E')
		return (get_str_path(type, EXIT, var));
	else if (type == 'X')
		return (get_str_path(type, ENEMIES, var));
	else
		return (ft_strdup(BASIC_TILES));
}
