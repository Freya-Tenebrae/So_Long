/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/23 11:55:29 by cmaginot         ###   ########.fr       */
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
	maps->x_lenght = 0;
	maps->y_lenght = 0;
	maps->mlx = NULL;
	maps->mlx_win = NULL;
	maps->tiles = NULL;
	maps->movements = 0;
	maps->collectible_total = 0;
	maps->collectible_count = 0;
	maps->status_game = 0;
	maps->n_frame = 0;
	maps->enemies = NULL;
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
	ft_free_map(&((*maps)->map));
	if ((*maps)->tiles != NULL)
		ft_free_tiles(&((*maps)->tiles));
	if ((*maps)->enemies != NULL)
		ft_free_enemies(&((*maps)->enemies));
	free(*maps);
}
