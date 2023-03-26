/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:27:11 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/26 20:34:58 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_alg(t_stacks *stacks)
{
//	int			size;
//	t_stack		*node_a;

//	node_a = *stacks->stack_a;
//	size = lstsize_n_check(node_a, NULL);
	pre_sort(stacks);
}

void	pre_sort(t_stacks *stacks)
{
	int			med_val;
	int			smallest;
//	t_stack		*node_a;

//	node_a = *stacks->stack_a;
	smallest = find_smallest(stacks);
	med_val = find_median(stacks, smallest);
	ft_printf("med_val  ;%d\n", med_val);
}

int	find_smallest(t_stacks *stacks)
{
	int			totsize;
	int			i;
	t_stack		*node_a;
	int			min;

	node_a = *stacks->stack_a;
	totsize = lstsize_n_check(node_a, NULL);
	i = 0;
	min = *node_a->content;
	while (i < totsize)
	{
		if (*node_a->content < min)
			min = *node_a->content;
		node_a = node_a->next;
		i++;
	}
	return (min);
}

int	find_median(t_stacks *stacks, int min)
{
	int			i;
	int			nextmin;
	t_stack		*node_a;
	int			totsize;

	i = 0;
	node_a = *stacks->stack_a;
	totsize = lstsize_n_check(node_a, NULL);
	while (i < totsize / 2)
	{
		nextmin = INT_MAX;
		node_a = *stacks->stack_a;
		while (node_a != NULL)
		{
			if (*node_a->content < nextmin && *node_a->content > min)
			{
				nextmin = *node_a->content;
			}
			node_a = node_a->next;
		}	
		min = nextmin;
		i++;
	}
	return (min);
}
