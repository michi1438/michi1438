/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:55:27 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/08 17:49:37 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
# include <limits.h>

int		pars(int ac, char **av);
void	err(void);
void	clean(void *ptr);
void	_clean_one(void *ptr);
void	_clean_dbl(char **ptr);
int		atoi_n_check(char *val);

#endif
