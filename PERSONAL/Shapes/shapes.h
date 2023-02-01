/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:28:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/01 12:36:31 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

#include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

typedef struct s_data {
	void	*img;
	char *addr;
	int	bits_per_pixels;
	int	line_length;
	int	endian;
}			t_data;


void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int	circlise(int x, int h);
int	circlise_two(int x, int h);

#endif
