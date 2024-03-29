/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hks_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:47:02 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/03 19:28:02 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_cleaner_mlx(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit (0);
}
