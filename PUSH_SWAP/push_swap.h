/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:55:27 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/11 23:23:57 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
# include <limits.h>

typedef struct s_stack{
	int		*content;
	void	*next;
	void	*prev;
}		t_stack;

typedef struct s_stacks{
	t_stack	stack_a;
	t_stack	stack_b;
}		t_stacks;

int			pars(int ac, char **av);
void		err(void);
void		clean(void *ptr);
void		_clean_one(void *ptr);
void		_clean_dbl(char **ptr);
int			atoi_n_check(char *val);
void		check_content(t_stacks *stacks);
t_stack		*lstnew(int *value);
void		lstadd_back(t_stacks **stacks, t_stack *new_a);
t_stack		*lstlast(t_stack *stack_a, int *value);
int			lstsize_n_check(t_stack *lst, int *value);
void		backward_check_content(t_stacks **stacks);
void		cleanlst(t_stacks *stacks);

#endif
