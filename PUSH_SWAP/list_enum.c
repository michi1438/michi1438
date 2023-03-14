/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_enum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:50:58 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/14 13:13:20 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_content(t_stacks *stacks)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = *stacks->stack_a;
	node_b = *stacks->stack_b;
	while (node_a != NULL)
	{
		printf("content_a :%d\n", *node_a->content);
		node_a = node_a->next;
	}
	while (node_b != NULL)
	{
		printf("content_b :%d\n", *node_b->content);
		node_b = node_b->next;
	}
	printf("\n");
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
		bkw_a = bkw_a->prev;
	}
	while (bkw_b != NULL)
	{
		printf("bkw_b_ content :%d\n", *bkw_b->content);
		bkw_b = bkw_b->prev;
	}
	printf("\n");
}
