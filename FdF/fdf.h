/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:28:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/12 19:43:40 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
#include "minilibx-linux/mlx.h"
#include <math.h>
#include <errno.h>
#define HEIGHT 1080 
#define WIDTH 1920
#define ER_NONUM "error, the word contains a nonnum value \n"
#define ER_RECT "error, the lines are not all of the same length...\n"
#define ER_NOTFDF "error, make sure your arg is a .fdf file\n"
#define ER_NOT1ARG "error, expected 1 arg\n"

typedef struct s_data {
	void	*mlx;
	void	*img;
	void *win;
	char *addr;
	int	bits_per_pixels;
	int	line_length;
	int	endian;
// to call through hooks.
	int	valcnt;
	int	wcount;
	int	**tab;
}			t_data;


void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int fdf_parser(int ac, char **av);
void	ft_putstr_fd(char *str, int fd);
char	*replace_nline(int fd, char *nline);
int	ft_putlineto_tab(int fd, int lines, int lonely_ret);
int	word_count(char **splited);
int	line_count(int fd);
int	koma_count(int fd);
int	lonely_ret_count(int fd);
int	contain_nonnum(char *word);
void enum_tab(int *tab, int val_count, int wcount);
unsigned int	ft_atohex(char *nptr);
void	start_graph(int wcount, int valcnt, int **tab);
void ft_err(char *err);
int	to_window_scale(int wcount, int valcnt);
void	draw(int i, t_data *img);
void	filltab(int *x, int *valcnt, char *nline, int **tab);
int	interact_mlx(int keycode, t_data *img);
void	fill_sct_hook(int *wcount, int *valcnt, int **tab, t_data *img);

#endif
