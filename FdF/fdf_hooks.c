/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:00:43 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/25 11:10:08 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_sct_hook(int *wcount, int *valcnt, int **tab, t_data *img)
{
	img->valcnt = *valcnt;
	img->wcount = *wcount;
	img->tab = tab;
	img->scaling = 0;
	img->x_axis = 0;
	img->y_axis = 0;
}

void	redo_img(t_data *img, int x, int y, int zoom)
{
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	img->scaling = zoom;
	img->x_axis = x;
	img->y_axis = y;
	draw(img->valcnt / img->wcount, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	interact_mlx(int keycode, t_data *img)
{
	static int	axis[2];
	static int	zoom;

	ft_printf("keycode ; %d\n", keycode);
	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	if (keycode == 45)
	{
		zoom -= 1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 43)
	{
		zoom += 1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	cardinal_displacement(keycode, img, axis, zoom);
	return (0);
}

void	cardinal_displacement(int keycode, t_data *img, int *axis, int zoom)
{
	if (keycode == 65362)
	{
		axis[1] += 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 65364)
	{
		axis[1] -= 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 124 || keycode == 65363)
	{
		axis[0] -= 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 65361)
	{
		axis[0] += 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
}