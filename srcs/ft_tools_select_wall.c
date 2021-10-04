/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_select_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/10/04 13:13:10 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static char	*ft_get_needed_wall_p1(t_maps *maps, int pos[2], char **str, \
									char **str_joined)
{
	if (maps->map[pos[1] - 1][pos[0] - 1] == '1')
		*str_joined = ft_strjoin(*str, "1");
	else
		*str_joined = ft_strjoin(*str, "0");
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	if (maps->map[pos[1] - 1][pos[0]] == '1')
		*str_joined = ft_strjoin(*str, "1");
	else
		*str_joined = ft_strjoin(*str, "0");
	free(*str);
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	if (maps->map[pos[1] - 1][pos[0] + 1] == '1')
		*str_joined = ft_strjoin(*str, "1");
	else
		*str_joined = ft_strjoin(*str, "0");
	free(*str);
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	return (*str);
}

static char	*ft_get_needed_wall_p2(t_maps *maps, int pos[2], char **str, \
									char **str_joined)
{
	if (maps->map[pos[1]][pos[0] - 1] == '1')
		*str_joined = ft_strjoin(*str, "1");
	else
		*str_joined = ft_strjoin(*str, "0");
	free(*str);
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	if (maps->map[pos[1]][pos[0] + 1] == '1')
		*str_joined = ft_strjoin(*str, "1");
	else
		*str_joined = ft_strjoin(*str, "0");
	free(*str);
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	return (*str);
}

static char	*ft_get_needed_wall_p3(t_maps *maps, int pos[2], char **str, \
									char **str_joined)
{
	if (pos[1] + 1 == maps->y_lenght)
		*str_joined = ft_strjoin(*str, "111");
	else
	{
		if (maps->map[pos[1] + 1][pos[0] - 1] == '1')
			*str_joined = ft_strjoin(*str, "1");
		else
			*str_joined = ft_strjoin(*str, "0");
	}
	free(*str);
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	return (*str);
}

static char	*ft_get_needed_wall_p4(t_maps *maps, int pos[2], char **str, \
									char **str_joined)
{
	if (pos[1] + 1 == maps->y_lenght)
		return (*str);
	if (maps->map[pos[1] + 1][pos[0]] == '1')
		*str_joined = ft_strjoin(*str, "1");
	else
		*str_joined = ft_strjoin(*str, "0");
	free(*str);
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	if (maps->map[pos[1] + 1][pos[0] + 1] == '1')
		*str_joined = ft_strjoin(*str, "1");
	else
		*str_joined = ft_strjoin(*str, "0");
	free(*str);
	if (*str_joined == NULL)
		return (NULL);
	*str = *str_joined;
	return (*str);
}

char	*ft_select_wall(t_maps *maps, int pos[2])
{
	char	*str;
	char	*str_joined;

	str = WALL_TO_DEFINE;
	if (ft_get_needed_wall_p1(maps, pos, &str, &str_joined) == NULL)
		return (NULL);
	if (ft_get_needed_wall_p2(maps, pos, &str, &str_joined) == NULL)
		return (NULL);
	if (ft_get_needed_wall_p3(maps, pos, &str, &str_joined) == NULL)
		return (NULL);
	if (ft_get_needed_wall_p4(maps, pos, &str, &str_joined) == NULL)
		return (NULL);
	str_joined = ft_strjoin(str, XPM);
	free(str);
	return (str_joined);
}
