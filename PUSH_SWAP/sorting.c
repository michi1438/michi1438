/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:06:07 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/17 15:38:17 by mguerga          ###   ########.fr       */
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
		ft_printf("send <= 5 args algorithm\n");
		check_content(stacks);
		under_six(stacks);
		check_content(stacks);
	}
	else
	{
		ft_printf("send > 7 args algorithm\n");
	}
}

void	under_six(t_stacks *stacks)
{
	int	minindex;
	int	size;
	int	totsize;

	size = lstsize_n_check(*stacks->stack_a, NULL);
	totsize = size;
	while (totsize - size < 3)
	{
		minindex = calc_small_index(*stacks->stack_a);
		if (minindex == 1)
			pb(stacks);
		else if (minindex == 2)
			sa(stacks);
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
