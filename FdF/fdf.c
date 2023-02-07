/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:28 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/07 18:50:33 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int	fd;
	int	lines;
	int	lonely_ret;

	if (fdf_parser(ac, av) == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	lonely_ret = lonely_ret_count(fd);
	fd = open(av[1], O_RDONLY);
	lines = line_count(fd);
	fd = open(av[1], O_RDONLY);
	ft_putlineto_tab(fd, lines, lonely_ret);
	return (1);
}

int	ft_putlineto_tab(int fd, int lines, int lonely_ret)
{
	int		x;
	int		valcnt;
	int		*tab[2];
	char	*nline;

	valcnt = 0;
	nline = get_next_line(fd);
	tab[0] = malloc(lines * sizeof(int) * word_count(ft_split(nline, ' ')));
	tab[1] = malloc(lines * sizeof(int) * word_count(ft_split(nline, ' ')));
	while (nline != NULL)
	{
		x = 0;
		while (ft_split(nline, ' ')[x] != NULL)
		{
			if (contain_nonnum(ft_split(nline, ' ')[x]) == 2)
			{
				ft_printf("error, the word contains a nonnum value\n");
				exit(1);
			}
			if (contain_nonnum(ft_split(nline, ' ')[x]) == 1)
			{
				tab[0][valcnt] = ft_atoi(ft_split(ft_split(nline, ' ')[x], ',')[0]);
				tab[1][valcnt++] = ft_atohex(ft_split(ft_split(nline, ' ')[x], ',')[1]);
			}
			else if (ft_split(nline, ' ')[x][0] != '\n')
			{	
				tab[0][valcnt] = ft_atoi(ft_split(nline, ' ')[x]);
				tab[1][valcnt++] = 0;
			}
			x++;
		}	
		nline = replace_nline(fd, nline);
	}
	free(nline);
	ft_printf("splt_sz; %d\ntot_sz; %d\nmal_sz; %d\nlon_ret; %d\n", x, valcnt, lines * x - lonely_ret, lonely_ret);
	if (valcnt % (x - lonely_ret) != 0)
	{
		ft_printf("error, the lines are not all of the same length...\n");
		exit(1);
	}
	enum_tab(tab[0], valcnt, x - (lonely_ret/lines));
	ft_printf("\n");
	//enum_tab(tab[1], valcnt, x - (lonely_ret/lines));
	return (fd);
}
