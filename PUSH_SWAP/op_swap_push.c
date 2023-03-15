/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:02:04 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/15 13:57:31 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_stack	*first_a;
	t_stack	*secon_a;
	int		*temp;

	first_a = *stacks->stack_a;
	if (lstsize_n_check(first_a, NULL) > 1)
	{
		temp = first_a->content;
		secon_a = first_a->next;
		first_a->content = secon_a->content;
		secon_a->content = temp;
		ft_printf("SA\n");
	}
	else
		ft_printf("SA err; less than two value in stack a\n");
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
		ft_printf("SB\n");
	}	
	else
		ft_printf("SB err; less than two val in stack b or value(s) are Null\n");
}

void	ss(t_stacks *stacks)
{
	ft_printf("SS includes :\n");
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks *stacks)
{
	int		*temp;
	t_stack	**node_a;

	node_a = stacks->stack_a;
	if (*node_a != NULL)
	{
		temp = (*node_a)->content;
		lstadd_front(stacks->stack_b, lstnew(temp));
		del_one_node(node_a);
		ft_printf("PA\n");
	}
	else
		ft_printf("PA err; no val in *stack_a\n");
}

void	pb(t_stacks *stacks)
{
	int		*temp;
	t_stack	**node_b;

	node_b = stacks->stack_b;
	if (*node_b != NULL)
	{
		temp = (*node_b)->content;
		lstadd_front(stacks->stack_a, lstnew(temp));
		del_one_node(node_b);
		ft_printf("PB\n");
	}
	else
		ft_printf("PA err; no val in *stack_b\n");
}
