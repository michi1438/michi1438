/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:17:24 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/10 18:19:58 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_input_ops(char *buf, t_stacks *stacks)
{
	if (ft_strncmp(buf, "pa\n", 3) == 0)
		pa_c(stacks);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		pb_c(stacks);
	else if (ft_strncmp(buf, "ra\n", 3) == 0)
		ra_c(stacks);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		rb_c(stacks);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
		rr_c(stacks);
	else if (ft_strncmp(buf, "sa\n", 3) == 0)
		sa_c(stacks);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		sb_c(stacks);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
		ss_c(stacks);
	else if (ft_strncmp(buf, "rra\n", 4) == 0)
		rra_c(stacks);
	else if (ft_strncmp(buf, "rrb\n", 4) == 0)
		rrb_c(stacks);
	else if (ft_strncmp(buf, "rrr\n", 4) == 0)
		rrr_c(stacks);
	else
		ft_err();
}
