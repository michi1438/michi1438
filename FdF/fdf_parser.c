/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:07:29 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/26 21:30:27 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	char	*isfdf;

	isfdf = ft_strnstr(av[1], ".fdf", 1000); 
	if (ac != 1)
	{
		ft_printf("error, expected 1 arg\n");
		return (0);
	}
	if (isfdf == NULL)
	{
    		ft_printf("error, make sure your arg is a .fdf file\n");	
		return (0);
	}
	return (1);
}

