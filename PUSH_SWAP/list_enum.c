/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_enum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:50:58 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/12 18:53:59 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_content(t_stacks *stacks)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = &stacks->stack_a;
	node_b = &stacks->stack_b;
	while (node_a->next != NULL)
	{
		node_a = node_a->next;
		node_b = node_b->next;
		printf("content_a :%d\n", *node_a->content);
		printf("content_b :%p\n", node_b->content);
	}
}

void	backward_check_content(t_stacks **stacks)
{
	t_stack	*bkw_a;
	t_stack	*bkw_b;
	int		value;

	value = -1;
	bkw_a = lstlast(&(*stacks)->stack_a, &value);
	bkw_b = lstlast(&(*stacks)->stack_b, &value);
	while (bkw_a->prev != NULL)
	{
		printf("bkw_a_ content :%d\n", *bkw_a->content);
		printf("bkw_b_ content :%p\n", bkw_b->content);
		bkw_a = bkw_a->prev;
		bkw_b = bkw_b->prev;
	}
}
