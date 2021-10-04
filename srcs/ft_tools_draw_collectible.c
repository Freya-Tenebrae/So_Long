/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_draw_collectible.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:28 by celia             #+#    #+#             */
/*   Updated: 2021/10/04 13:53:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

int	ft_draw_collectible(void *mlx, t_data **scene, t_maps *maps, int pos[2])
{
	ft_fill_img(mlx, &((*scene)[pos[0] + pos[1] * \
		maps->x_lenght]), BASIC_TILES);
	return (0);
}
