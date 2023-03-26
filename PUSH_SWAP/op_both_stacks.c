/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:32:30 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/25 10:38:46 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stacks *stacks)
{
	t_stack	*first_a;
	t_stack	*secon_a;
	t_stack	*first_b;
	t_stack	*secon_b;
	int		*temp;

	first_a = *stacks->stack_a;
	if (lstsize_n_check(first_a, NULL) > 1 && first_a->content != NULL)
	{
		temp = first_a->content;
		secon_a = first_a->next;
		first_a->content = secon_a->content;
		secon_a->content = temp;
	}
	first_b = *stacks->stack_b;
	if (lstsize_n_check(first_b, NULL) > 1 && first_b->content != NULL)
	{
		temp = first_b->content;
		secon_b = first_b->next;
		first_b->content = secon_b->content;
		secon_b->content = temp;
	}	
	ft_printf("ss\n");
}

void	rrr(t_stacks *stacks)
{
	t_stack	**node_a;
	t_stack	**node_b;
	int		*temp;

	node_a = stacks->stack_a;
	if (*node_a != NULL && lstsize_n_check(*node_a, NULL) > 1)
	{
		temp = lstlast(*node_a, NULL)->content;
		del_last_node(node_a);
		lstadd_front(node_a, lstnew(temp));
	}
	node_b = stacks->stack_b;
	if (*node_b != NULL && lstsize_n_check(*node_b, NULL) > 1)
	{
		temp = lstlast(*node_b, NULL)->content;
		del_last_node(node_b);
		lstadd_front(node_b, lstnew(temp));
	}
	ft_printf("rrr\n");
}

void	rr(t_stacks *stacks)
{
	t_stack	**node_a;
	int		*temp;
	t_stack	**node_b;

	node_a = stacks->stack_a;
	if (*node_a != NULL && lstsize_n_check(*node_a, NULL) > 1)
	{
		temp = (*node_a)->content;
		del_first_node(node_a);
		lstadd_back(node_a, lstnew(temp));
	}
	node_b = stacks->stack_b;
	if (*node_b != NULL && lstsize_n_check(*node_b, NULL) > 1)
	{
		temp = (*node_b)->content;
		del_first_node(node_b);
		lstadd_back(node_b, lstnew(temp));
	}
	ft_printf("rr\n");
}
