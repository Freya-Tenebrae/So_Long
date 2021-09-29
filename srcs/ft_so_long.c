/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/29 20:09:35 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	main(int argc, const char **argv)
{
	t_maps	*maps;
	char	*result;

	if (argc != 2)
		ft_error("incorect numbers of arguments");
	maps = ft_init_maps();
	if (!maps)
		ft_error("malloc error");
	maps->map = NULL;
	ft_get_map(&(maps->map), argv[1]);
	ft_check_map_validity((const char **)maps->map);
	ft_get_size_map(&maps);
	result = ft_game_init(maps);
	ft_free_maps(&maps);
	if (ft_strcmp(result, "") == 0)
		return (0);
	ft_error(result);
}
