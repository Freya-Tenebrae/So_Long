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

static t_maps	*ft_init_maps()
{
	t_maps	*maps;

	maps = malloc(sizeof(t_maps));
	if (!maps)
		return (NULL);
	maps->map = NULL;
	maps->next = NULL;
	return (maps);
}

int	main(int argc, const char **argv)
{
	t_maps	*maps;
	t_maps	*maps_ptr;

	if (argc < 2)
		ft_error("incorect numbers of arguments");
	maps = ft_init_maps();
	if (!maps)
		ft_error("malloc error");
	maps_ptr = maps;
	while (maps_ptr != NULL)
	{
		ft_get_map(&(maps_ptr->map), argv[1]);
		ft_check_map_validity(&(maps_ptr->map));
		ft_free_map(&(maps_ptr->map));
		maps_ptr = maps_ptr->next;
	}
}
