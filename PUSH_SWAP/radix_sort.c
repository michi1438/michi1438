/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:18:40 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/09 23:45:56 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stacks *stacks)
{
	int		i;
	int		size;
	int		bufsize;
	t_stack	*node_a;

	i = 1;
	node_a = *stacks->stack_a;
	size = indexify(stacks);
	bufsize = size;
	while (i < 9)
	{
		while (size > 1)
		{
			if ((*node_a->index >> i & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
			node_a = *stacks->stack_a;
			size--;
		}
		if (i < 8)
			empty_stack_b(stacks);
		else
		{
			empty_stack_a(stacks);
			sorting(stacks);
		}
		size = bufsize;
		node_a = *stacks->stack_a;
		i++;
	}
}

void	empty_stack_a(t_stacks *stacks)
{
	t_stack	*node_a;

	node_a = *stacks->stack_a;
	while (node_a != NULL)
	{
		pb(stacks);
		node_a = *stacks->stack_a;
	}
}

void	push_index_radix(int ind, int size, t_stacks *stacks)
{
	t_stack		*node_a;
	int			i;

	node_a = *stacks->stack_a;
	i = 0;
	while (*node_a->index != ind && i++ < INT_MAX)
		node_a = node_a->next;
	node_a = *stacks->stack_a;
	if (i < size / 2)
	{
		while (i-- > 0)
		{
			ra(stacks);
			node_a = *stacks->stack_a;
		}
	}
	else
	{
		while (i++ < size)
		{
			rra(stacks);
			node_a = *stacks->stack_a;
		}
	}
	pb(stacks);
}
