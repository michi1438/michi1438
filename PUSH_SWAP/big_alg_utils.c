/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_alg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:59:40 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/18 13:41:57 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stacks	*stacks)
{
	t_stack	*node_a;
	t_stack	*nxt_a;

	node_a = *stacks->stack_a;
	nxt_a = node_a->next;
	while (node_a != NULL)
	{
		if (nxt_a != NULL && *node_a->content >= *nxt_a->content)
			return (1);
		node_a = node_a->next;
		if (node_a != NULL)
			nxt_a = node_a->next;
	}
	return (0);
}

int	indexify(t_stacks *stacks)
{
	int			i;
	int			totsize;
	t_stack		*node_a;
	int			nextmin;
	int			min;

	i = 0;
	min = find_smallest(stacks);
	node_a = *stacks->stack_a;
	totsize = lstsize_n_check(node_a, NULL);
	while (i++ < totsize)
	{
		nextmin = INT_MAX;
		node_a = *stacks->stack_a;
		while (node_a != NULL)
		{
			if (*node_a->content < nextmin && *node_a->content > min)
				nextmin = *node_a->content;
			node_a = node_a->next;
		}	
		min = nextmin;
		node_a = *stacks->stack_a;
		give_index(i, min, stacks);
	}
	return (i);
}

void	sorting_inner(t_stacks *stacks, int size, int index_max)
{
	int			i;
	t_stack		*node_b;

	i = 0;
	node_b = *stacks->stack_b;
	while (*node_b->index != index_max)
	{
		i++;
		node_b = node_b->next;
	}
	if (i <= (size / 2))
	{
		while (i-- > 1)
			rb(stacks);
		rb_sb_ss(stacks, index_max);
	}
	else
	{
		while (i++ < size - 1)
			rrb(stacks);
		rrb_sb(stacks);
	}
	pa(stacks);
}

void	rrb_sb(t_stacks *stacks)
{
	t_stack		*node_b;
	t_stack		*next_b;

	node_b = *stacks->stack_b;
	next_b = node_b->next;
	if (next_b != NULL && *next_b->index > *node_b->index)
		sb(stacks);
	rrb(stacks);
}

void	rb_sb_ss(t_stacks *stacks, int index_max)
{
	t_stack	*node_b;
	t_stack	*nxt_b;

	node_b = *stacks->stack_b;
	nxt_b = node_b->next;
	if (nxt_b != NULL && *nxt_b->index == *node_b->index + 1)
		sb(stacks);
	else if (*node_b->index != index_max)
		rb(stacks);
}
