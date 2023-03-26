/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:55:27 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/26 23:50:44 by mguerga          ###   ########.fr       */
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
	t_stack	**stack_a;
	t_stack	**stack_b;
}		t_stacks;

int			pars(int ac, char **av);
void		err(void);
void		clean(void *ptr);
void		_clean_one(void *ptr);
void		_clean_dbl(char **ptr);
int			atoi_n_check(char *val);
void		check_content(t_stacks *stacks);
t_stack		*lstnew(int *value);
void		lstadd_back(t_stack **stack, t_stack *new_a);
t_stack		*lstlast(t_stack *stack_a, int *value);
int			lstsize_n_check(t_stack *lst, int *value);
void		backward_check_content(t_stacks **stacks);
void		cleanlst(t_stacks *stacks);
void		start_sort(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		lstadd_front(t_stack **stack, t_stack *new);
void		del_first_node(t_stack **stack);
void		del_last_node(t_stack **node);
void		under_six(t_stacks *stacks);
int			calc_small_index(t_stack *node);
void		empty_stack_b(t_stacks *stacks);
void		sort_restof_a(t_stacks *stacks);
void		pre_sort(t_stacks *stacks);
void		big_alg(t_stacks *stacks);
int			find_smallest(t_stacks *stacks);
int			find_median(t_stacks *stacks, int min);

#endif
