/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:25:10 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/28 21:33:23 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	enum_tab(int *tab, int val_count, int wcount)
{
	int	i;

	i = 0;
	while (val_count > 0)
	{
		ft_printf("%d ", tab[i]);
		if ((i + 1) % wcount == 0)
			write (1, "\n", 1);
		i++;
		val_count--;
	}
}
