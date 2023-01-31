/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:06 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/31 14:51:07 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	int	offset;
	char	*dst;

	offset = (img->line_length * y + (img->bits_per_pixels/8) * x);
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}
