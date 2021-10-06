/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 03:17:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	ft_check_if_file_is_ber(const char *path)
{
	int		path_len;

	path_len = ft_strlen(path);
	if (path_len <= 4)
		return (-1);
	if (ft_strcmp(&(path[path_len - 4]), ".ber") != 0)
		return (-1);
	return (0);
}

void	ft_free_map(char ***map)
{
	int	n;

	n = 0;
	while ((*map)[n] != NULL)
	{
		free((*map)[n]);
		(*map)[n++] = NULL;
	}
	free(*map);
	*map = NULL;
}

static void	ft_add_line_on_map(char ***map, char **line, int n_line, \
								int status_gnl)
{
	char	**strs;
	int		n;

	if (status_gnl != -1)
	{
		strs = malloc(sizeof(char *) * (n_line + 2));
		if (!strs)
		{
			ft_free_map(map);
			ft_error("malloc error");
		}
		n = -1;
		while (++n < n_line)
			strs[n] = (*map)[n];
		strs[n] = *line;
		n += 1;
		strs[n] = 0;
		free(*map);
		*map = strs;
	}
	line = NULL;
}

void	ft_get_map(char ***map, const char *path)
{
	int		fd;
	int		status_gnl;
	int		n_line;
	char	*line;

	fd = open(path, O_RDONLY);
	status_gnl = 1;
	n_line = 0;
	line = NULL;
	if (fd < 0 || ft_check_if_file_is_ber(path) != 0)
		ft_error("incorrect file path");
	while (status_gnl == 1)
	{
		status_gnl = get_next_line(fd, &line);
		ft_add_line_on_map(map, &line, n_line, status_gnl);
		n_line += 1;
	}
	if (status_gnl == -1)
	{
		ft_free_map(map);
		ft_error("GNL failed to read the file");
	}
	close(fd);
}
