/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_maps_memory_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/27 11:00:44 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

t_maps	*ft_init_maps(void)
{
	t_maps	*maps;

	maps = malloc(sizeof(t_maps));
	if (!maps)
		return (NULL);
	maps->map = NULL;
	maps->next = NULL;
	return (maps);
}

void	ft_free_maps(t_maps **maps)
{
	t_maps	*maps_ptr;

	maps_ptr = *maps;
	while (maps_ptr != NULL)
	{
		ft_free_map(&(maps_ptr->map));
		maps_ptr = maps_ptr->next;
		free(*maps);
		*maps = maps_ptr;
	}	
}
