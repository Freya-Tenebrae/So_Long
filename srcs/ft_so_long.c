/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/27 11:37:32 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	main(int argc, const char **argv)
{
	char	**map;
	char	*result;

	if (argc != 2)
		ft_error("incorect numbers of arguments");
	map = NULL;
	ft_get_map(&map, argv[1]);
	ft_check_map_validity((const char **)map);
	result = ft_game_init(map);
	ft_free_map(&map);
	if (ft_strcmp(result, "") == 0)
		return (0);
	ft_error(result);
}
