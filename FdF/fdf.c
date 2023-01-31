/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:28 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/31 16:56:23 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av) 
{
	int	fd;
	char *nline;

	if (fdf_parser(ac, av) == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	nline = get_next_line(fd);
	while (nline != NULL)
	{
		ft_putstr_fd(nline, 1);
		nline = replace_nline(fd, nline);
	}
	free(nline);
	return (fd);
}

int fdf_parser(int ac, char **av)
{
	char *isfdf;

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

