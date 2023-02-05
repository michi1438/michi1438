/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:37:57 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/04 20:39:53 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_parser(int ac, char **av)
{
	char	*isfdf;

	if (ac != 2)
	{
		ft_printf("error, expected 1 arg\n");
		return (0);
	}
	isfdf = ft_strnstr(av[1], ".fdf", 1000);
	if (isfdf == NULL)
	{
		ft_printf("error, make sure your arg is a .fdf file\n");
		return (0);
	}
	return (1);
}
