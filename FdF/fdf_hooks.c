/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:00:43 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/01 11:52:59 by mguerga          ###   ########.fr       */
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
	img->accentuate = 1;
	img->x_rot = 2;
	img->scaling = to_window_scale(img->wcount, img->valcnt);
}

void	redo_img(t_data *img, int x, int y, int zoom)
{
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	img->scaling = to_window_scale(img->wcount, img->valcnt) + zoom;
	img->x_axis = x;
	img->y_axis = y;
	draw(img->valcnt / img->wcount, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

