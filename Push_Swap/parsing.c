/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:04:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/08 17:07:56 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		_pars_one(char *av);
int		_pars_mult(int ac, char **av);

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
	int		value;

	i = 0;
	splited = ft_split(av, ' ');
	while (splited[i] != NULL)
	{
		j = 0;
		while (splited[i][j] != '\0')
		{
			if (ft_isalpha(splited[i][j]))
				return (1);
			j++;
		}
		value = atoi_n_check(splited[i++]);
		ft_printf("%d\n", value);
	}
	_clean_dbl(splited);
	return (0);
}

int	_pars_mult(int ac, char **av)
{
	int		i;
	int		j;
	int		value;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((ft_isalpha(av[i][j++])))
				return (1);
		}
		value = atoi_n_check(av[i]);
		ft_printf("%d\n", value);
		i++;
	}
	return (0);
}
