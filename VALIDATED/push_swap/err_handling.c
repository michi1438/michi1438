/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:47:57 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/22 12:43:03 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	*p_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_printf("couldn't allocate memory\n");
		ft_err();
	}
	return (ptr);
}

void	*p_malloc_clean(size_t size, t_stacks *stacks)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_printf("couldn't allocate memory\n");
		cleanlst(stacks);
		ft_err();
	}
	return (ptr);
}
