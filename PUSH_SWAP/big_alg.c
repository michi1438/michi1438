/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:44:52 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/13 10:45:08 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_alg(t_stacks *stacks)
{
	cluster_pre_sort(stacks);
	sorting(stacks);
}

void	cluster_pre_sort(t_stacks *stacks)
{
	t_stack		*node_a;
	int			size;

	indexify(stacks);
	node_a = *stacks->stack_a;
	while (node_a != NULL)
	{
		size = lstsize_n_check(node_a, NULL);
		push_index(find_cheapest(stacks), size, stacks);
		node_a = *stacks->stack_a;
	}
}

int	find_cheapest(t_stacks *stacks)
{
	t_stack		*node_a;
	int			i;
	int			cheap_ind[3];
	int			size;

	i = 0;
	node_a = *stacks->stack_a;
	size = lstsize_n_check(node_a, NULL);
	cheap_ind[1] = INT_MAX;
	while (node_a != NULL)
	{
		if ((*node_a->index) + distance(i, size) < cheap_ind[1])
		{
			cheap_ind[0] = *node_a->index;
			cheap_ind[1] = *node_a->index + distance(i, size);
			cheap_ind[2] = distance(i, size);
		}
		else if ((*node_a->index) + distance(i, size) == cheap_ind[1])
			if (distance(i, size) < cheap_ind[2])
				cheap_ind[0] = *node_a->index;
		node_a = node_a->next;
		i++;
	}
	return (cheap_ind[0]);
}

void	push_index(int ind, int size, t_stacks *stacks)
{
	t_stack		*node_a;
	t_stack		*node_b;
	int			i;

	node_a = *stacks->stack_a;
	node_b = *stacks->stack_b;
	i = 0;
	while (*node_a->index != ind)
	{
		node_a = node_a->next;
		i++;
	}
	node_a = *stacks->stack_a;
	if (i <= size / 2)
	{
		rot_to_ind_a(stacks, ind, i);
	}
	else
	{
		while (i++ < size - 1)
		{
			if (node_b != NULL && *node_b->index < *lstlast(node_b, NULL)->index)
				rrr(stacks);
			else
				rra(stacks);
			node_a = *stacks->stack_a;
			node_b = *stacks->stack_b;
		}
		rra_sa_rrr(stacks);
	}
	pb(stacks);
}

void	rra_sa_rrr(t_stacks *stacks)
{
	t_stack		*node_a;
	t_stack		*next_a;
	t_stack		*node_b;
	t_stack		*last_b;

	node_a = *stacks->stack_a;
	node_b = *stacks->stack_b;
	next_a = node_a->next;
	last_b = lstlast(node_b, NULL);
	if (next_a != NULL && *next_a->index < *node_a->index)
		sa(stacks);
	if (node_b != NULL && *last_b->index > *node_b->index)
	{
		rrr(stacks);
	}
	else
		rra(stacks);
}
