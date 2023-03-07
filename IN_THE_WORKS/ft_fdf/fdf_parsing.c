/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:37:57 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/02 19:59:14 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_parser(int ac, char **av)
{
	char	*isfdf;

	if (ac != 2)
		ft_sterror(ER_NOT1ARG);
	isfdf = ft_strnstr(av[1], ".fdf", 1000);
	if (isfdf == NULL)
		ft_sterror(ER_NOTFDF);
	return (1);
}
