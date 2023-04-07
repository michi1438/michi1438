/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both_stacks_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:32:30 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/06 15:20:22 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_c(t_stacks *stacks)
{
	t_stack	*first_a;
	t_stack	*secon_a;
	int		*temp;
	int		temp_index;

	first_a = *stacks->stack_a;
	if (lstsize_n_check(first_a, NULL) > 1 && first_a->content != NULL)
	{
		temp = first_a->content;
		temp_index = *first_a->index;
		secon_a = first_a->next;
		first_a->content = secon_a->content;
		*first_a->index = *secon_a->index;
		secon_a->content = temp;
		*secon_a->index = temp_index;
	}
	ss__sb_c(stacks);
}

void	ss__sb_c(t_stacks *stacks)
{
	t_stack	*first_b;
	t_stack	*secon_b;
	int		*temp;
	int		temp_index;

	first_b = *stacks->stack_b;
	if (lstsize_n_check(first_b, NULL) > 1 && first_b->content != NULL)
	{
		temp = first_b->content;
		temp_index = *first_b->index;
		secon_b = first_b->next;
		first_b->content = secon_b->content;
		*first_b->index = *secon_b->index;
		secon_b->content = temp;
		*secon_b->index = temp_index;
	}	
}

void	rrr_c(t_stacks *stacks)
{
	t_stack	**node_a;
	t_stack	**node_b;
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

void	rr_c(t_stacks *stacks)
{
	t_stack	**node_a;
	int		*temp;
	int		temp_index;
	t_stack	**node_b;

	node_a = stacks->stack_a;
	if (*node_a != NULL && lstsize_n_check(*node_a, NULL) > 1)
	{
		temp = (*node_a)->content;
		temp_index = *(*node_a)->index;
		del_first_node(node_a);
		node_a = stacks->stack_a;
		lstadd_back(node_a, lstnew(temp));
		*lstlast(*node_a, NULL)->index = temp_index;
	}
	node_b = stacks->stack_b;
	if (*node_b != NULL && lstsize_n_check(*node_b, NULL) > 1)
	{
		temp = (*node_b)->content;
		temp_index = *(*node_b)->index;
		del_first_node(node_b);
		node_b = stacks->stack_b;
		lstadd_back(node_b, lstnew(temp));
		*lstlast(*node_b, NULL)->index = temp_index;
	}
}
