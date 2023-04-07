/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both_stacks_supl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:11:50 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/06 15:13:45 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr__rb(t_stacks *stacks)
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
		node_b = stacks->stack_b;
		lstadd_back(node_b, lstnew(temp));
		*lstlast(*node_b, NULL)->index = temp_index;
	}
	ft_printf("rr\n");
}
