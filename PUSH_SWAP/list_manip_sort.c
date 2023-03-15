/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:11:38 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/15 16:36:39 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

void	del_one_node(t_stack **node)
{
	if ((*node)->next != NULL && *node != NULL)
	{
		*node = (*node)->next;
		free((*node)->prev);
		(*node)->prev = NULL;
	}
	else
	{
		(*node)->content = NULL;
		free(*node);
		*node = NULL;
	}
}
