/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:04:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/10 13:34:36 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		_pars_one(char *av, t_stack *stack_a);
int		_pars_mult(int ac, char **av, t_stack *stack_a);

int	pars(int ac, char **av)
{
	t_stack	stack_a;

	if (ac == 2)
		return (_pars_one(av[1], &stack_a));
	else if (ac > 2)
		return (_pars_mult(ac, av, &stack_a));
	else if (ac == 1)
		return (1);
	else
		return (0);
}

int	_pars_one(char *av, t_stack *stack_a)
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
		lstadd_back(&stack_a, lstnew(value));
	}
	check_content(stack_a);
	backward_check_content(&stack_a);
	_clean_dbl(splited);
	//cleanlst(stack_a);
	return (0);
}

int	_pars_mult(int ac, char **av, t_stack *stack_a)
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
		lstadd_back(&stack_a, lstnew(value));
		i++;
	}
	check_content(stack_a);
	backward_check_content(&stack_a);
	//cleanlst(stack_a);
	return (0);
}
