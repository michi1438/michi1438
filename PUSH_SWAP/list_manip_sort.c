/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:11:38 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/05 21:42:07 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_front(t_stack **stack, t_stack *new)
{
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

void	del_first_node(t_stack **node)
{
	if ((*node)->next != NULL && *node != NULL)
	{
		free((*node)->index);
		*node = (*node)->next;
		free((*node)->prev);
		(*node)->prev = NULL;
	}
	else
	{
		(*node)->content = NULL;
		free((*node)->index);
		free(*node);
		*node = NULL;
	}
}

void	del_last_node(t_stack **node)
{
	t_stack	*last;

	last = lstlast(*node, NULL);
	free(last->index);
	last = last->prev;
	free(last->next);
	last->next = NULL;
}
