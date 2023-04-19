/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:52:14 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/04 06:07:55 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_perr(char *err)
{
	perror(err);
	ft_printf("\n");
	exit (1);
}

void	ft_sterror(char *err)
{
	(void)err;
	ft_printf("Error: %s\n", err);
	exit (1);
}
