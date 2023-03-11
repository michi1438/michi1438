/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:04:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/11 12:12:13 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		_pars_one(char *av, t_stacks *stack);
int		_pars_mult(int ac, char **av, t_stacks *stacks);

int	pars(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (ac == 2)
		return (_pars_one(av[1], stacks));
	else if (ac > 2)
		return (_pars_mult(ac, av, stacks));
	else if (ac == 1)
		return (1);
	else
		return (0);
}

int	_pars_one(char *av, t_stacks *stacks)
{
	int		i;
	int		j;
	char	**splited;
	int		*value;

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
		value = malloc(sizeof(int));
		*value = atoi_n_check(splited[i++]);
		lstadd_back(&stacks, lstnew(value));
	}
	check_content(stacks);
	backward_check_content(&stacks);
	_clean_dbl(splited);
	//cleanlst(stacks);
	return (0);
}

int	_pars_mult(int ac, char **av, t_stacks *stacks)

{
	int		i;
	int		j;
	int		*value;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((ft_isalpha(av[i][j++])))
				return (1);
		}
		value = malloc(sizeof(int));
		*value = atoi_n_check(av[i]);
		lstadd_back(&stacks, lstnew(value));
		i++;
	}
	check_content(stacks);
	backward_check_content(&stacks);
	//cleanlst(stacks);
	return (0);
}
