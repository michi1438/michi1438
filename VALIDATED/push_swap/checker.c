/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:45 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/22 12:34:52 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		_pars_mult_check(int ac, char **av, t_stacks *stacks);
int		_pars_one_check(char *av, t_stacks *stack);

int	main(int ac, char **av)
{
	if (pars_checker(ac, av) != 0)
		ft_err();
	else
		return (0);
}

int	pars_checker(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = p_malloc(sizeof(t_stacks));
	stacks->stack_a = p_malloc(sizeof(t_stack));
	stacks->stack_b = p_malloc(sizeof(t_stack));
	if (ac == 2)
		return (_pars_one_check(av[1], stacks));
	else if (ac > 2)
		return (_pars_mult_check(ac, av, stacks));
	else if (ac == 1)
	{
		cleanlst(stacks);
		return (0);
	}
	else
		return (1);
}

int	_pars_one_check(char *av, t_stacks *stacks)
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
		value = p_malloc_clean(sizeof(int), stacks);
		*value = atoi_n_check(splited[i++]);
		lstadd_back(stacks->stack_a, lstnew((int *)value));
	}
	if (splited[0] != NULL)
	{
		take_input(stacks);
		_clean_dbl(splited);
	}
	cleanlst(stacks);
	return (0);
}

int	_pars_mult_check(int ac, char **av, t_stacks *stacks)
{
	int		i;
	int		j;
	int		*value;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		value = p_malloc_clean(sizeof(int), stacks);
		*value = atoi_n_check(av[i]);
		lstadd_back(stacks->stack_a, lstnew(value));
		i++;
	}
	take_input(stacks);
	cleanlst(stacks);
	return (0);
}

void	take_input(t_stacks *stacks)
{
	char	*buf;	

	indexify(stacks);
	buf = get_next_line(0);
	while (buf != NULL)
	{
		take_input_ops(buf, stacks);
		free(buf);
		buf = get_next_line(0);
	}
	if (is_ordered(stacks) == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
