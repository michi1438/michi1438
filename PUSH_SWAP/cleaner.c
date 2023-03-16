/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:15:31 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/17 00:33:47 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*free_n_next(t_stack *node);

/*
void	clean(void *ptr)
{
	
	ft_printf("%p\n", ptr);
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

	ret = NULL;
	if (node->next != NULL)
		ret = node->next;
	free(node);
	return (ret);
}

void	cleanlst(t_stacks *stacks)
{
	t_stack	**node_a;
	t_stack	**node_b;

	node_a = stacks->stack_a;
	node_b = stacks->stack_b;
	while (*node_a != NULL)
	{
		free((*node_a)->content);
		*node_a = free_n_next(*node_a);
	}
	free(node_a);
	while (node_b != NULL && (*node_b) != NULL)
	{
		free((*node_b)->content);
		*node_b = free_n_next(*node_b);
	}
	free(node_b);
	free(stacks);
}
