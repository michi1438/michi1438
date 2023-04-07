/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:04:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/05 14:19:57 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		_pars_one(char *av, t_stacks *stack);
int		_pars_mult(int ac, char **av, t_stacks *stacks);

int	pars(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->stack_a = malloc(sizeof(t_stack));
	stacks->stack_b = malloc(sizeof(t_stack));
	if (ac == 2)
		return (_pars_one(av[1], stacks));
	else if (ac > 2)
		return (_pars_mult(ac, av, stacks));
	else if (ac == 1)
		return (0);
	else
		return (1);
}

int	_pars_one(char *av, t_stacks *stacks)
{
	int				i;
	int				j;
	char			**splited;
	long int		*value;

	i = 0;
	splited = ft_split(av, ' ');
	if (av[0] == '\0')
		exit (0);
	while (splited[i] != NULL)
	{
		j = 0;
		while (splited[i][j] != '\0')
			j++;
		value = malloc(sizeof(int));
		*value = atoi_n_check(splited[i++]);
		lstadd_back(stacks->stack_a, lstnew((int *)value));
	}
	start_sort(stacks);
	_clean_dbl(splited);
	cleanlst(stacks);
	return (0);
}

int	_pars_mult(int ac, char **av, t_stacks *stacks)
{
	int				i;
	int				j;
	long int		*value;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		value = malloc(sizeof(int));
		*value = atoi_n_check(av[i]);
		lstadd_back(stacks->stack_a, lstnew((int *)value));
		i++;
	}
	start_sort(stacks);
	cleanlst(stacks);
	return (0);
}
