/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:28 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/03 20:06:21 by mguerga          ###   ########.fr       */
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
	if (fd == -1)
		ft_perr(ER);
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
	create_tab(tab, lines, wcount);
	while (nline != NULL)
	{
		x = 0;
		filltab(&x, &valcnt, nline, tab);
		nline = replace_nline(fd, nline);
	}
	free(nline);
	if (valcnt % (x - lonely_ret) != 0)
		ft_sterror(ER_RECT);
	start_graph(wcount, valcnt, tab);
	free(tab[0]);
	free(tab[1]);
	return (fd);
}

void	create_tab(int **tab, int lines, int wcount)
{
	tab[0] = malloc(lines * sizeof(int) * wcount);
	if (tab[0] == NULL)
		ft_sterror(ER_NOSPACE);
	tab[1] = malloc(lines * sizeof(int) * wcount);
	if (tab[1] == NULL)
	{
		free(tab[0]);
		ft_sterror(ER_NOSPACE);
	}
}

char	*replace_nline(int fd, char *nline)
{
	char	*nptr;

	nptr = get_next_line(fd);
	free (nline);
	return (nptr);
}

void	filltab(int *x, int *valcnt, char *nline, int **tab)
{
	char	**splited;
	char	**splited_2;

	splited = ft_split(nline, ' ');
	while (splited[*x] != NULL)
	{
		if (contain_nonnum(splited[*x]) == 2)
			ft_sterror(ER_NONUM);
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
