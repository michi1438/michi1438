/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:28:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/01 10:41:01 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <errno.h>
# define HEIGHT 1080 
# define WIDTH 1920
# define ER_NONUM "error, the word contains a nonnum value \n"
# define ER_RECT "error, the lines are not all of the same length...\n"
# define ER_NOTFDF "error, make sure your arg is a .fdf file\n"
# define ER_NOT1ARG "error, expected 1 arg\n"

typedef struct s_data {
	void	*mlx;

	void	*img;
	void	*win;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;

// to call through hooks.
	int		valcnt;
	int		wcount;
	int		**tab;
	int		scaling;
	int		x_axis;
	int		y_axis;
	float	accentuate;
	float	x_rot;
}			t_data;

void	redo_img(t_data *img, int x, int y, int zoom);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		fdf_parser(int ac, char **av);
void	ft_putstr_fd(char *str, int fd);
char	*replace_nline(int fd, char *nline);
int		ft_putlineto_tab(int fd, int lines, int lonely_ret);
int		word_count(char **splited);
int		line_count(int fd);
int		lonely_ret_count(int fd);
int		contain_nonnum(char *word);
void	enum_tab(int *tab, int val_count, int wcount);
unsigned int		ft_atohex(char *nptr);
void	start_graph(int wcount, int valcnt, int **tab);
void	ft_err(char *err);
int		to_window_scale(int wcount, int valcnt);
void	draw(int i, t_data *img);
void	filltab(int *x, int *valcnt, char *nline, int **tab);
int		keyboard_mlx(int keycode, t_data *img);
void	fill_sct_hook(int *wcount, int *valcnt, int **tab, t_data *img);
void	cardinal_displacement(int keycode, t_data *img, int *axis, int zoom);
void	complet_hlines(int *axis, t_data *img, int e);
void	complet_vlines(int *axis, t_data *img, int e);
void	horizontal_line(t_data *img, int *axis, int e);
void	vertical_line(t_data *img, int *axis, int e);
void	place_nodes(t_data *img, int *e, int *j, int *i);
void	accentuate_terrain(int keycode, t_data *img, int *axis, int zoom);
void	clean(char **splited);
int button_mlx(int button, int x, int y, t_data *img);

#endif
