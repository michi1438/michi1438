/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:06:07 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/26 19:45:33 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stacks *stacks)
{
	t_stack	*node_a;

	node_a = *stacks->stack_a;
	if (lstsize_n_check(node_a, NULL) < 2)
		exit(1);
	if (lstsize_n_check(node_a, NULL) < 7)
	{
		ft_printf("send < 7 args algorithm\n");
		under_six(stacks);
		sort_restof_a(stacks);
		empty_stack_b(stacks);
		check_content(stacks);
	}
	else
	{
		ft_printf("send > 7 args algorithm\n");
		big_alg(stacks);
	}
}

void	empty_stack_b(t_stacks *stacks)
{
	while (*stacks->stack_b != NULL)
	{
		pa(stacks);
	}
}

void	under_six(t_stacks *stacks)
{
	int	minindex;
	int	size;

	size = lstsize_n_check(*stacks->stack_a, NULL);
	while (size > 3)
	{
		minindex = calc_small_index(*stacks->stack_a);
		if (minindex == 1)
			pb(stacks);
		else if (minindex == 2)
			ra(stacks);
		else if (size - minindex < 2)
			rra(stacks);
		else if (size - minindex > 1)
			ra(stacks);
		size = lstsize_n_check(*stacks->stack_a, NULL);
	}
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
		if (cont1 > cont2)
			sa(stacks);
		else if (cont2 > cont3)
			rra(stacks);
		node = *stacks->stack_a;
		cont1 = *node->content;
		node = node->next;
		cont2 = *node->content;
		node = node->next;
		cont3 = *node->content;
	}
}
