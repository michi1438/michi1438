/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:52:14 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/02 20:30:13 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_perr(char *err)
{
	perror(err);
	exit (1);
}

void	ft_sterror(char *err)
{
	(void)err;
	ft_printf("Error: %s\n", err);
	exit	(1);
}
