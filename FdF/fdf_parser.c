/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:07:29 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/28 17:30:18 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
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

