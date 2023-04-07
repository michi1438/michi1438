/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:31 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/05 16:35:10 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*free_n_next(t_stack *node);

void	_clean_dbl(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i++]);
	}
	free(ptr);
}

t_stack	*free_n_next(t_stack *node)
{
	t_stack	*ret;

	ret = NULL;
	if (node->next != NULL)
	{
		ret = node->next;
	}
	free(node);
	return (ret);
}

void	cleanlst(t_stacks *stacks)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = *stacks->stack_a;
	while (node_a != NULL)
	{
		free(node_a->content);
		free(node_a->index);
		node_a = free_n_next(node_a);
	}
	free(stacks->stack_a);
	node_b = *stacks->stack_b;
	while (node_b != NULL)
	{
		free(node_b->content);
		free(node_b->index);
		node_b = free_n_next(node_b);
	}
	free(stacks->stack_b);
	free(stacks);
}
