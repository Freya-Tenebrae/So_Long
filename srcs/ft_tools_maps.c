/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/29 20:08:07 by cmaginot         ###   ########.fr       */
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
	maps->type = 0;
	maps->x_lenght = 0;
	maps->y_lenght = 0;
	maps->next = NULL;
	return (maps);
}

void	ft_get_size_map(t_maps **maps)
{
	(*maps)->x_lenght = (int)ft_strlen((*maps)->map[0]);
	while ((*maps)->map[(*maps)->y_lenght] != NULL)
		(*maps)->y_lenght += 1;
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
