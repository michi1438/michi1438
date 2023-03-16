/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:06:07 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/17 00:12:51 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stacks *stacks)
{
	t_stack	*node_a;

	node_a = *stacks->stack_a;
	if (lstsize_n_check(node_a, NULL) < 2)
		exit(1);
	if (lstsize_n_check(node_a, NULL) < 7)
	{
		ft_printf("send <= 5 args algorithm\n");
		check_content(stacks);
		sa(stacks);
		pb(stacks);
		pb(stacks);
		pb(stacks);
		rr(stacks);
		rrr(stacks);
		sa(stacks);
		pa(stacks);
		pa(stacks);
		pa(stacks);
		check_content(stacks);
	}
	else
	{
		ft_printf("send > 7 args algorithm\n");
	}
}
