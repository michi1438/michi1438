/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:18:40 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/16 23:59:10 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	t_stack	**node_a;
	int		*temp;

	node_a = stacks->stack_a;
	if (*node_a != NULL && lstsize_n_check(*node_a, NULL) > 1)
	{
		temp = (*node_a)->content;
		del_first_node(node_a);
		lstadd_back(node_a, lstnew(temp));
		ft_printf("ra\n");
	}
}

void	rb(t_stacks *stacks)
{
	t_stack	**node_b;
	int		*temp;

	node_b = stacks->stack_b;
	if (*node_b != NULL && lstsize_n_check(*node_b, NULL) > 1)
	{
		temp = (*node_b)->content;
		del_first_node(node_b);
		lstadd_back(node_b, lstnew(temp));
		ft_printf("rb\n");
	}
}

void	rra(t_stacks *stacks)
{
	t_stack	**node_a;
	int		*temp;

	node_a = stacks->stack_a;
	if (*node_a != NULL && lstsize_n_check(*node_a, NULL) > 1)
	{
		temp = lstlast(*node_a, NULL)->content;
		del_last_node(node_a);
		lstadd_front(node_a, lstnew(temp));
		ft_printf("rra\n");
	}
}

void	rrb(t_stacks *stacks)
{
	t_stack	**node_b;
	int		*temp;

	node_b = stacks->stack_b;
	if (*node_b != NULL && lstsize_n_check(*node_b, NULL) > 1)
	{
		temp = lstlast(*node_b, NULL)->content;
		del_last_node(node_b);
		lstadd_front(node_b, lstnew(temp));
		ft_printf("rrb\n");
	}
}
