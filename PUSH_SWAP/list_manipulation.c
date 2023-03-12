/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:14:05 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/12 19:13:36 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int *value)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr == NULL)
		err();
	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->content = value;
	return (ptr);
}

void	lstadd_back(t_stacks **stacks, t_stack *new_a)
{
	t_stack	*last_a;
	t_stack	*node_a;
	t_stack	*last_b;
	t_stack	*node_b;
	t_stack	*new_b;

	new_b = lstnew(NULL);
	node_a = &(*stacks)->stack_a;
	node_b = &(*stacks)->stack_b;
	if (node_a != NULL)
	{
		last_a = lstlast(node_a, new_a->content);
		last_b = lstlast(node_b, new_b->content);
		new_a->prev = last_a;
		last_a->next = new_a;
		new_b->prev = last_b;
		last_b->next = new_b;
	}
	else
	{
		node_a = new_a;
		node_b = new_b;
	}
}

t_stack	*lstlast(t_stack *stack_a, int *value)
{
	t_stack		*fwd;
	int			lastn;
	int			i;

	fwd = stack_a;
	i = 0;
	lastn = lstsize_n_check(fwd, value);
	while (i < (lastn - 1))
	{
		fwd = fwd->next;
		i++;
	}
	return (fwd);
}

int	lstsize_n_check(t_stack *lst, int *val)
{
	int			i;
	t_stack		*fwd;

	i = 0;
	fwd = lst;
	while (fwd != NULL)
	{
		if (val != NULL && fwd->content != NULL && *fwd->content == *val)
			err();
		fwd = fwd->next;
		i++;
	}
	return (i);
}
