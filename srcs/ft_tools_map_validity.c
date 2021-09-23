/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_map_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/12 16:27:12 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	ft_check_map_validity_rectangle(char ***map)
{
	int	size_first_line;
	int	n_line;

	size_first_line = (int)ft_strlen((*map)[0]);
	if (size_first_line < 3)
		ft_error("the map is too small");
	n_line = 1;
	while ((*map)[n_line] != NULL)
	{
		if ((int)ft_strlen((*map)[n_line]) != size_first_line)
			ft_error("the map isn't rectangular");
		n_line += 1;
	}
	if (n_line < 3)
		ft_error("the map is too small");
}

static void	ft_check_map_validity_souronding(char ***map)
{
	(void)map;
}

static void	ft_check_map_validity_all_actor_are_valid(char ***map)
{
	(void)map;
}

static void	ft_check_map_validity_all_actor_present_once(char ***map)
{
	(void)map;
}

void	ft_check_map_validity(char ***map)
{
	if (*map == NULL)
		ft_error("the map is empty");
	ft_check_map_validity_rectangle(map);
	ft_check_map_validity_souronding(map);
	ft_check_map_validity_all_actor_are_valid(map);
	ft_check_map_validity_all_actor_present_once(map);
}
