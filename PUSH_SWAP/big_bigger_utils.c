/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_bigger_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:25:24 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/17 12:16:01 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_ind_a(t_stacks *stacks, int ind, int i)
{
	t_stack		*node_a;
	t_stack		*nxt_a;
	t_stack		*node_b;
	t_stack		*nxt_b;

	node_b = *stacks->stack_b;
	while (i-- > 1)
	{
		rot_shrinker(stacks);
		node_b = *stacks->stack_b;
	}
	node_a = *stacks->stack_a;
	nxt_a = node_a->next;
	node_b = *stacks->stack_b;
	nxt_b = node_a->next;
	if (node_a != NULL && nxt_a != NULL && *nxt_a->index == *node_a->index - 1)
	{
		if (node_b != NULL && nxt_b != NULL && *nxt_b->index > *node_b->index)
			ss(stacks);
		else
			sa(stacks);
	}
	else if (node_a != NULL && *node_a->index != ind)
		ra(stacks);
}

void	rot_shrinker(t_stacks *stacks)
{
	t_stack		*node_b;

	node_b = *stacks->stack_b;
	if (node_b != NULL && *node_b->index > *(lstlast(node_b, NULL)->index))
		rr(stacks);
	else
		ra(stacks);
}

void	give_index(int i, int min, t_stacks *stacks)
{
	t_stack		*node_a;

	node_a = *stacks->stack_a;
	while (node_a != NULL)
	{
		if (*node_a->content == min)
			*node_a->index = i;
		node_a = node_a->next;
	}
}

void	give_index_b(int i, int max, t_stacks *stacks)
{
	t_stack		*node_a;

	node_a = *stacks->stack_a;
	while (node_a != NULL)
	{
		if (*node_a->content == max)
			*node_a->index = i;
		node_a = node_a->next;
	}
}

void	sorting(t_stacks *stacks)
{
	int			index_max;
	int			size;
	t_stack		*node_b;

	node_b = *stacks->stack_b;
	index_max = find_largest_b(stacks);
	size = lstsize_n_check(node_b, NULL);
	while (size > 1)
	{
		sorting_inner(stacks, size, index_max);
		node_b = *stacks->stack_b;
		size = lstsize_n_check(node_b, NULL);
		index_max = find_largest_b(stacks);
	}
}
