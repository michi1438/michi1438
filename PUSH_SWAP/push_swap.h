/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:55:27 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/12 17:29:29 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
# include <limits.h>

typedef struct s_stack{
	int		*content;
	int		*index;
	void	*next;
	void	*prev;
}		t_stack;

typedef struct s_stacks{
	t_stack	**stack_a;
	t_stack	**stack_b;
}		t_stacks;

int			pars(int ac, char **av);
void		ft_err(void);
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
void		sa_c(t_stacks *stacks);
void		sb_c(t_stacks *stacks);
void		ss_c(t_stacks *stacks);
void		pa_c(t_stacks *stacks);
void		pb_c(t_stacks *stacks);
void		ra_c(t_stacks *stacks);
void		rb_c(t_stacks *stacks);
void		rr_c(t_stacks *stacks);
void		rra_c(t_stacks *stacks);
void		rrb_c(t_stacks *stacks);
void		rrr_c(t_stacks *stacks);
void		lstadd_front(t_stack **stack, t_stack *new);
void		del_first_node(t_stack **stack);
void		del_last_node(t_stack **node);
void		under_six(t_stacks *stacks);
int			calc_small_index(t_stack *node);
void		empty_stack_b(t_stacks *stacks);
void		sort_restof_a(t_stacks *stacks);
void		three_node_sort(t_stacks *stacks, int cont1, int cont2, int cont3);
void		pre_sort(t_stacks *stacks);
int			find_smallest(t_stacks *stacks);
int			abs(int val);
int			distance(int i, int size);
void		sorting(t_stacks *stacks);
int			find_largest_b(t_stacks *stacks);
int			pars_checker(int ac, char **av);
void		big_alg(t_stacks *stacks);
void		cluster_pre_sort(t_stacks *stacks);
void		cluster_rev_sort(t_stacks *stacks);
int			indexify(t_stacks *stacks);
int			indexify_b(t_stacks *stacks);
void		push_index(int pivot, int size, t_stacks *stacks);
void		push_index_b(int ind, int size, t_stacks *stacks);
int			find_cheapest(t_stacks *stacks);
int			find_cheapest_b(t_stacks *stacks);
void		rot_to_ind_a(t_stacks *stacks, int ind, int i);
void		give_index(int i, int min, t_stacks *stacks);
void		give_index_b(int i, int max, t_stacks *stacks);
void		rb_sb_ss(t_stacks *stacks, int index_max);
void		rra_sa_rrr(t_stacks *stacks);
void		rrb_sb(t_stacks *stacks);
void		take_input(t_stacks *stacks);
void		radix_sort(t_stacks *stacks);
void		push_index_radix(int ind, int size, t_stacks *stacks);
int			is_ordered(t_stacks	*stacks);
void		take_input_ops(char *buf, t_stacks *stacks);
int			distance_to(t_stack *node_b, int index_max);
void		sorting_inner(t_stacks *stacks, int size, int index_max);
void		ss__sb(t_stacks *stacks);
void		rrr__rrb(t_stacks *stacks);
void		rr__rb(t_stacks *stacks);
void		ss__sb_c(t_stacks *stacks);
int			no_other_candidat(t_stacks *stacks, int i, int size);
void		empty_stack_a(t_stacks *stacks);

#endif
