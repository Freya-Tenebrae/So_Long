/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:27:34 by cmaginot          #+#    #+#             */
/*   Updated: 2021/10/06 04:02:00 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_success(void)
{
	ft_putstr_fd("the program 'so_long' has been correclty executed.\n", 1);
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error : ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(".\n", 1);
	exit(EXIT_FAILURE);
}
