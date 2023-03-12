/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:31 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/12 19:15:34 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*free_n_next(t_stack *node);

/*
void	clean(void *ptr)
{
	
	printf("%p\n", ptr);
}
*/

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

	ret = node->next;
	free(node);
	return (ret);
}

void	cleanlst(t_stacks *stacks)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = &stacks->stack_a;
	node_b = &stacks->stack_b;
	while (node_a != NULL)
	{
		if (node_a->content != NULL)
			free(node_a->content);
		if (node_a != NULL)
			node_a = free_n_next(node_a);
	}
	while (node_b != NULL)
	{
		if (node_b->content != NULL)
			free(node_a->content);
		if (node_b != NULL && node_b->next != NULL)
			node_b = free_n_next(node_b);
	}
}
