/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/12 16:27:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	main(int argc, const char **argv)
{
	char	***map;
	int		n_map;

	if (argc < 2)
		ft_error("incorect numbers of arguments");
	n_map = -1;
	map = malloc(sizeof(char **) * (argc));
	if (!map)
		ft_error("malloc error");
	map[argc - 1] = NULL;
	while (++n_map < argc - 1)
	{
		ft_get_map(&(map[n_map]), argv[1]);
		ft_check_map_validity(&(map[n_map]));
		ft_free_map(&(map[n_map]));
	}
}
