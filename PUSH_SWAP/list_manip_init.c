/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:14:05 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/14 11:48:56 by mguerga          ###   ########.fr       */
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

void	lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;
	t_stack	**node;

	node = stack;
	if (*node != NULL)
	{
		last = lstlast(*node, new->content);
		new->prev = last;
		last->next = new;
	}
	else
		*node = new;
}

t_stack	*lstlast(t_stack *stack, int *value)
{
	t_stack		*fwd;
	int			lastn;
	int			i;

	fwd = stack;
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
