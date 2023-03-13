/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_enum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:50:58 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/13 10:36:02 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_content(t_stacks *stacks)
{
	t_stack	*node_a;

	node_a = *stacks->stack_a;
	while (node_a != NULL)
	{
		printf("content_a :%d\n", *node_a->content);
		node_a = node_a->next;
	}
}

void	backward_check_content(t_stacks **stacks)
{
	t_stack	*bkw_a;
	t_stack	*bkw_b;

	bkw_a = lstlast(*(*stacks)->stack_a, NULL);
	bkw_b = lstlast(*(*stacks)->stack_b, NULL);
	while (bkw_a != NULL)
	{
		printf("bkw_a_ content :%d\n", *bkw_a->content);
		printf("bkw_b_ content :%p\n", bkw_b->content);
		bkw_a = bkw_a->prev;
		bkw_b = bkw_b->prev;
	}
}
