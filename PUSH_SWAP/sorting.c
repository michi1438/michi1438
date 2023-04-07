/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:06:07 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/07 18:09:22 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stacks *stacks)
{
	t_stack	*node_a;
	t_stack	*nxt_a;

	node_a = *stacks->stack_a;
	nxt_a = node_a->next;
	if (lstsize_n_check(node_a, NULL) < 2)
		exit(0);
	else if (lstsize_n_check(node_a, NULL) == 2)
	{
		if (*node_a->content > *nxt_a->content)
			sa(stacks);
	}
	else if (lstsize_n_check(node_a, NULL) < 7)
		under_six(stacks);
	else if (lstsize_n_check(node_a, NULL) < 200)
	{
		if (is_ordered(stacks) != 0)
			big_alg(stacks);
	}
	else
	{
		if (is_ordered(stacks) != 0)
			radix_sort(stacks);
	}
}

void	under_six(t_stacks *stacks)
{
	int		minindex;
	int		size;
	t_stack	*node;

	node = *stacks->stack_a;
	size = lstsize_n_check(node, NULL);
	while (size > 3)
	{
		minindex = calc_small_index(node);
		if (minindex == 1)
			pb(stacks);
		else if (minindex == 2)
			ra(stacks);
		else if (size - minindex < 3)
			rra(stacks);
		else if (size - minindex > 2)
			ra(stacks);
		node = *stacks->stack_a;
		size = lstsize_n_check(node, NULL);
	}
	sort_restof_a(stacks);
	empty_stack_b(stacks);
}

int	calc_small_index(t_stack *node)
{
	int		totsize;
	int		min;
	int		y;
	int		minindex;

	totsize = lstsize_n_check(node, NULL);
	y = 0;
	min = *node->content;
	minindex = 1;
	while (y < totsize)
	{
		if (*node->content < min)
		{
			min = *node->content;
			minindex = y + 1;
		}
		node = node->next;
		y++;
	}
	return (minindex);
}

void	sort_restof_a(t_stacks *stacks)
{
	int		cont1;
	int		cont2;
	int		cont3;
	t_stack	*node;

	node = *stacks->stack_a;
	cont1 = *node->content;
	node = node->next;
	cont2 = *node->content;
	node = node->next;
	cont3 = *node->content;
	while (!(cont1 < cont2 && cont2 < cont3))
	{
		three_node_sort(stacks, cont1, cont2, cont3);
		node = *stacks->stack_a;
		cont1 = *node->content;
		node = node->next;
		cont2 = *node->content;
		node = node->next;
		cont3 = *node->content;
	}
}

void	three_node_sort(t_stacks *stacks, int cont1, int cont2, int cont3)
{
	if (cont1 > cont3)
		ra(stacks);
	else if (cont1 > cont2)
		sa(stacks);
	else if (cont2 > cont3)
		rra(stacks);
}
