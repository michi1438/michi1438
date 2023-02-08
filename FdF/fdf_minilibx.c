/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:29:51 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/08 13:46:58 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	int	offset;
	char	*dst;

	offset = (img->line_length * y + (img->bits_per_pixels/8) * x);
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}
