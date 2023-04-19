/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:18:40 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/06 11:30:35 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_c(t_stacks *stacks)
{
	t_stack	**node_a;
	int		*temp;
	int		temp_index;

	node_a = stacks->stack_a;
	if (*node_a != NULL && lstsize_n_check(*node_a, NULL) > 1)
	{
		temp = (*node_a)->content;
		temp_index = *(*node_a)->index;
		del_first_node(node_a);
		lstadd_back(node_a, lstnew(temp));
		node_a = stacks->stack_a;
		*lstlast(*node_a, NULL)->index = temp_index;
	}
}

void	rb_c(t_stacks *stacks)
{
	t_stack	**node_b;
	int		*temp;
	int		temp_index;

	node_b = stacks->stack_b;
	if (*node_b != NULL && lstsize_n_check(*node_b, NULL) > 1)
	{
		temp = (*node_b)->content;
		temp_index = *(*node_b)->index;
		del_first_node(node_b);
		lstadd_back(node_b, lstnew(temp));
		node_b = stacks->stack_b;
		*lstlast(*node_b, NULL)->index = temp_index;
	}
}

void	rra_c(t_stacks *stacks)
{
	t_stack	**node_a;
	int		*temp;
	int		temp_index;

	node_a = stacks->stack_a;
	if (*node_a != NULL && lstsize_n_check(*node_a, NULL) > 1)
	{
		temp = lstlast(*node_a, NULL)->content;
		temp_index = *lstlast(*node_a, NULL)->index;
		del_last_node(node_a);
		lstadd_front(node_a, lstnew(temp));
		node_a = stacks->stack_a;
		*(*node_a)->index = temp_index;
	}
}

void	rrb_c(t_stacks *stacks)
{
	t_stack	**node_b;
	int		*temp;
	int		temp_index;

	node_b = stacks->stack_b;
	if (*node_b != NULL && lstsize_n_check(*node_b, NULL) > 1)
	{
		temp = lstlast(*node_b, NULL)->content;
		temp_index = *lstlast(*node_b, NULL)->index;
		del_last_node(node_b);
		lstadd_front(node_b, lstnew(temp));
		node_b = stacks->stack_b;
		*(*node_b)->index = temp_index;
	}
}
