/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:04:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/07 19:16:57 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pars(int ac, char **av)
{
	if (ac == 2)
		return (_pars_one(av[1]));
	else if (ac > 2)
		return (_pars_mult(ac, av));
	else if (ac == 1)
		return (1);
	else
		return (0);
}

int	_pars_one(char *av)
{
	int		i;
	int		j;
	char	**splited;

	i = 0;
	splited = ft_split(av, ' ');
	while (splited[i] != NULL)
	{
		j = 0;
		while (splited[i][j] != '\0')
		{
			if (!(ft_isdigit(splited[i][j])))
				return (1);
			j++;
		}
		ft_printf("%s\n", splited[i++]);
	}
	_clean_dbl(splited);
	return (0);
}

int	_pars_mult(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!(ft_isdigit(av[i][j])))
				return (1);
			j++;
		}
		ft_printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
