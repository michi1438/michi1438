/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:28:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/31 17:00:57 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

typedef struct s_data {
	void	*img;
	char *addr;
	int	bits_per_pixels;
	int	line_length;
	int	endian;
}			t_data;


void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int fdf_parser(int ac, char **av);
void	ft_putstr_fd(char *str, int fd);
char	*replace_nline(int fd, char *nline);

#endif
