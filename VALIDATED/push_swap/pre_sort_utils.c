/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:37:58 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/12 16:34:36 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int val)
{
	if (val < 0)
		val *= -1;
	return (val);
}

void	empty_stack_b(t_stacks *stacks)
{
	while (*stacks->stack_b != NULL)
		pa(stacks);
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

int	find_largest_b(t_stacks *stacks)
{
	t_stack		*node_b;
	int			max;

	node_b = *stacks->stack_b;
	max = *node_b->index;
	while (node_b != NULL)
	{
		if (*node_b->index > max)
			max = *node_b->index;
		node_b = node_b->next;
	}
	return (max);
}

int	distance(int i, int size)
{
	if (i <= size / 2)
	{
		return (i);
	}
	else
	{
		return (size - i);
	}
}
