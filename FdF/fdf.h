/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:28:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/05 18:11:28 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
int fdf_parser(int ac, char **av);
void	ft_putstr_fd(char *str, int fd);
char	*replace_nline(int fd, char *nline);
int	ft_putlineto_tab(int fd, int lines, int komas, int lonely_ret);
int	word_count(char **splited);
int	line_count(int fd);
int	koma_count(int fd);
int	lonely_ret_count(int fd);
int	contain_nonnum(char *word);
void enum_tab(int *tab, int val_count, int x);

#endif
