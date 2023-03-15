/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:06:07 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/15 17:14:54 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stacks *stacks)
{
	t_stack	*node_a;

	node_a = *stacks->stack_a;
	if (lstsize_n_check(node_a, NULL) < 2)
		exit(1);
	if (lstsize_n_check(node_a, NULL) < 6)
	{
		ft_printf("send <= 5 args algorithm\n");
		check_content(stacks);
		sa(stacks);
		sb(stacks);
		pb(stacks);
		check_content(stacks);
	}
	else
	{
		ft_printf("send > 5 args algorithm\n");
	}
}
