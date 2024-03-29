/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:28:34 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/06 17:27:20 by mguerga          ###   ########.fr       */
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
# define ER_NONUM "The file contains an unhandled value (\"0123456789 ,xX\\n\").\n"
# define ER_RECT "The lines are not all of the same length...\n"
# define ER_NOTFDF "Make sure your arg is a .fdf file.\n"
# define ER_NOT1ARG "Expected 1 arg.\n"
# define ER_NOSPACE "Malloc failed not enough space.\n"
# define ER "Error"

typedef struct s_data
{
	int		bpp;
	int		llen;
	int		endi;
	int		valcnt;
	int		wcount;
	int		**tab;
	int		scaling;
	int		x_axis;
	int		y_axis;
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	float	accentuate;
}	t_data;

unsigned int	ft_atohex(char *nptr);
int				fdf_parser(int ac, char **av);
void			redo_img(t_data *img, int x, int y, int zoom);
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
void			ft_putstr_fd(char *str, int fd);
char			*replace_nline(int fd, char *nline);
int				ft_putlineto_tab(int fd, int lines, int lonely_ret);
int				word_count(char **splited);
int				line_count(int fd);
int				lonely_ret_count(int fd);
int				contain_nonnum(char *word);
void			enum_tab(int *tab, int val_count, int wcount);
void			start_graph(int wcount, int valcnt, int **tab);
void			ft_sterror(char *err);
int				to_window_scale(int wcount, int valcnt);
void			draw(int i, t_data *img);
void			filltab(int *x, int *valcnt, char *nline, int **tab);
int				destroy_cleaner_mlx(t_data *img);
int				keyboard_mlx(int keycode, t_data *img);
void			fill_sct_hook(int *wcount, int *valcnt, int **tab, t_data *img);
void			moving(int keycode, t_data *img, int *axis, int zoom);
void			complet_hlines(int *axis, t_data *img, int e);
void			complet_vlines(int *axis, t_data *img, int e);
void			horizontal_line(t_data *img, int *axis, int e);
void			vertical_line(t_data *img, int *axis, int e);
void			place_nodes(t_data *img, int *e, int *j, int *i);
void			accent(int keycode, t_data *img, int *axis, int zoom);
void			clean(char **splited);
void			ft_perr(char *err);
void			create_tab(int **tab, int lines, int wcount);
int				calc_offelev(t_data *img);

#endif
