/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:02:04 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/13 09:29:58 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_stack	*first_a;
	t_stack	*secon_a;
	int		*temp;

	first_a = &stacks->stack_a;
	first_a = first_a->next;
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

	first_b = &stacks->stack_b;
	first_b = first_b->next;
	if (lstsize_n_check(first_b, NULL) > 1 && first_b->content != NULL)
	{
		temp = first_b->content;
		secon_b = first_b->next;
		first_b->content = secon_b->content;
		secon_b->content = temp;
		ft_printf("SB\n");
	}	
	else
		ft_printf("SB err; less than two value in stack b or value(s) are Null\n");
}


void	ss(t_stacks *stacks)
{
	ft_printf("SS includes :\n");
	sa(stacks);
	sb(stacks);
}


