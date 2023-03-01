/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:28 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/28 22:49:14 by mguerga          ###   ########.fr       */
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
	int		wcount;
	char	*nline;

	valcnt = 0;
	nline = get_next_line(fd);
	wcount = word_count(ft_split(nline, ' '));
	tab[0] = malloc(lines * sizeof(int) * wcount);
	tab[1] = malloc(lines * sizeof(int) * wcount);
	while (nline != NULL)
	{
		x = 0;
		filltab(&x, &valcnt, nline, tab);
		nline = replace_nline(fd, nline);
	}
	free(nline);
	if (valcnt % (x - lonely_ret) != 0)
		ft_err(ER_RECT);
	start_graph(wcount, valcnt, tab);
	free(tab[0]);
	free(tab[1]);
	return (fd);
}

void	filltab(int *x, int *valcnt, char *nline, int **tab)
{
	char	**splited;
	char	**splited_2;

	splited = ft_split(nline, ' ');
	while (splited[*x] != NULL)
	{
		if (contain_nonnum(splited[*x]) == 2)
		{
			clean(splited);
			ft_err(ER_NONUM);
		}
		if (contain_nonnum(splited[*x]) == 1)
		{
			splited_2 = ft_split(splited[*x], ',');
			tab[0][*valcnt] = ft_atoi(splited_2[0]);
			tab[1][(*valcnt)++] = ft_atohex(splited_2[1]);
			clean(splited_2);
		}
		else if (splited[*x][0] != '\n')
		{	
			tab[0][*valcnt] = ft_atoi(splited[*x]);
			tab[1][(*valcnt)++] = 0;
		}
		(*x)++;
	}	
	clean(splited);
}
