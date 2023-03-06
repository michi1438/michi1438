/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hks_keyboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:49:22 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/06 17:31:21 by mguerga          ###   ########.fr       */
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
		if (img->scaling > 1)
			zoom -= 1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 43 || keycode == 69)
	{
		zoom += 1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	moving(keycode, img, axis, zoom);
	accent(keycode, img, axis, zoom);
	return (0);
}

void	accent(int keycode, t_data *img, int *axis, int zoom)
{
	if (keycode == 75 || keycode == 47)
	{
		img->accentuate -= 0.1;
		redo_img(img, axis[0], axis[1], zoom);
	}
	if (keycode == 67 || keycode == 42)
	{
		img->accentuate += 0.1;
		redo_img(img, axis[0], axis[1], zoom);
	}
}

void	moving(int keycode, t_data *img, int *axis, int zoom)
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
