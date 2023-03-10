/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:14:05 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/10 13:37:21 by mguerga          ###   ########.fr       */
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
	ptr->content = value;
	return (ptr);
}

void	lstadd_back(t_stack **stack_a, t_stack *new)
{
	t_stack	*last;

	if (*stack_a != NULL)
	{
		last = lstlast(*stack_a, new->content);
		new->prev = last;
		last->next = new;
	}
	else
		*stack_a = new;
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

int	lstsize_n_check(t_stack *lst, int *value)
{
	int			i;
	t_stack		*fwd;

	i = 0;
	fwd = lst;
	while (fwd != NULL)
	{
		//printf("stack's pointer :%p\n", fwd);
		if (fwd->content != NULL && *fwd->content == *value)
			err();
		fwd = fwd->next;
		i++;
	}
	return (i);
}

void	check_content(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		stack_a = stack_a->next;
		printf("content :%d\n", *stack_a->content);
	}
}

void	backward_check_content(t_stack **stack_a)
{
	t_stack	*bkw;
	int		value = -1;

	bkw = lstlast(*stack_a, &value);
	while (bkw->prev != NULL)
	{
		printf("bkw content :%d\n", *bkw->content);
		bkw = bkw->prev;
	}
}
