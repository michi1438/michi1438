/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:02:04 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/06 11:28:54 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_c(t_stacks *stacks)
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
}

void	sb_c(t_stacks *stacks)
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

void	pb_c(t_stacks *stacks)
{
	int		*temp;
	int		temp_index;
	t_stack	**node_a;
	t_stack	**node_b;

	node_a = stacks->stack_a;
	if (*node_a != NULL)
	{
		temp = (*node_a)->content;
		temp_index = *(*node_a)->index;
		lstadd_front(stacks->stack_b, lstnew(temp));
		node_b = stacks->stack_b;
		*(*node_b)->index = temp_index;
		del_first_node(node_a);
	}
}

void	pa_c(t_stacks *stacks)
{
	int		*temp;
	int		temp_index;
	t_stack	**node_b;
	t_stack	**node_a;

	node_b = stacks->stack_b;
	if (*node_b != NULL)
	{
		temp = (*node_b)->content;
		temp_index = *(*node_b)->index;
		lstadd_front(stacks->stack_a, lstnew(temp));
		node_a = stacks->stack_a;
		*(*node_a)->index = temp_index;
		del_first_node(node_b);
	}
}
