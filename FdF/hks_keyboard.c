/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hks_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:49:22 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/01 11:54:37 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

int	keyboard_mlx(int keycode, t_data *img)
{
	static int	axis[2];
	static int	zoom;

	if (keycode == 65307 || keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	if (keycode == 45 || keycode == 78)
	{
		zoom -= 1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 43 || keycode == 69)
	{
		zoom += 1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	cardinal_displacement(keycode, img, axis, zoom);
	accentuate_terrain(keycode, img, axis, zoom);
	return (0);
}

void	accentuate_terrain(int keycode, t_data *img, int *axis, int zoom)
{
	if (keycode == 75)
	{
		img->accentuate -= 0.1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 67)
	{
		img->accentuate += 0.1;
		redo_img(img, axis[0], axis[1], zoom);
	}
}

void	cardinal_displacement(int keycode, t_data *img, int *axis, int zoom)
{
	if (keycode == 65362 || keycode == 125)
	{
		axis[1] += 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 65364 || keycode == 126)
	{
		axis[1] -= 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 124 || keycode == 65363)
	{
		axis[0] -= 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 65361 || keycode == 123)
	{
		axis[0] += 20;
		redo_img(img, axis[0], axis[1], zoom);
	}
}
