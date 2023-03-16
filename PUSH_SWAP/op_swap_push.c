/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:02:04 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/17 00:18:33 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_stack	*first_a;
	t_stack	*secon_a;
	int		*temp;

	first_a = *stacks->stack_a;
	if (lstsize_n_check(first_a, NULL) > 1 && first_a->content != NULL)
	{
		temp = first_a->content;
		secon_a = first_a->next;
		first_a->content = secon_a->content;
		secon_a->content = temp;
		ft_printf("sa\n");
	}
}

void	sb(t_stacks *stacks)
{
	t_stack	*first_b;
	t_stack	*secon_b;
	int		*temp;

	first_b = *stacks->stack_b;
	if (lstsize_n_check(first_b, NULL) > 1 && first_b->content != NULL)
	{
		temp = first_b->content;
		secon_b = first_b->next;
		first_b->content = secon_b->content;
		secon_b->content = temp;
		ft_printf("sb\n");
	}	
}

void	pb(t_stacks *stacks)
{
	int		*temp;
	t_stack	**node_a;

	node_a = stacks->stack_a;
	if (*node_a != NULL)
	{
		temp = (*node_a)->content;
		lstadd_front(stacks->stack_b, lstnew(temp));
		del_first_node(node_a);
		ft_printf("pb\n");
	}
}

void	pa(t_stacks *stacks)
{
	int		*temp;
	t_stack	**node_b;

	node_b = stacks->stack_b;
	if (*node_b != NULL)
	{
		temp = (*node_b)->content;
		lstadd_front(stacks->stack_a, lstnew(temp));
		del_first_node(node_b);
		ft_printf("pa\n");
	}
}
