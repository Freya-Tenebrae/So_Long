/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/09/24 08:27:46 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(".\n", 1);
	exit(EXIT_FAILURE);
}
