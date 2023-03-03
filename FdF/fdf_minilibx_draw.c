/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_minilibx_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:30:27 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/03 19:49:28 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_nodes(t_data *img, int *e, int *j, int *i)
{
	int		ax[7];
	float	elev;
	int		scale;

	scale = img->scaling;
	if ((img->tab)[1][*e] == 0)
		(img->tab)[1][*e] = 0x00FF0000;
	ax[0] = ((WIDTH / 2) + img->x_axis) + (*j - *i) * scale;
	elev = ((float)((img->tab)[0][*e])) * img->accentuate;
	ax[1] = (img->y_axis + (*i + *j - (elev)) * scale / sqrt(2));
	ax[4] = ((WIDTH / 2) + img->x_axis) + (*j - (*i + 1)) * scale;
	if (*e + img->wcount < img->valcnt)
		elev = (float)(img->tab)[0][*e + img->wcount] * img->accentuate;
	ax[5] = (img->y_axis + ((*i + 1 + *j) - elev) * scale / sqrt(2));
	if (*i < img->valcnt / img->wcount)
		vertical_line(img, ax, *e);
	(*j)++;
	ax[2] = ((WIDTH / 2) + img->x_axis) + (*j - *i) * scale;
	if (*e + 1 < img->valcnt)
		elev = (float)(img->tab)[0][*e + 1] * img->accentuate;
	ax[3] = (img->y_axis + (*i + *j - elev) * scale / sqrt(2));
	if (*j < img->wcount)
		horizontal_line(img, ax, *e);
}

void	vertical_line(t_data *img, int *ax, int e)
{
	int	inc;

	inc = 0;
	ax[2] = 0;
	while (ax[2] < ax[0] - 1)
	{
		ax[2] = ax[4] + inc;
		ax[3] = ax[5] + inc * (ax[1] - ax[5]) / (ax [0] - ax[4]);
		ax[6] = ax[5] + inc + 1 * (ax[1] - ax[5]) / (ax[0] - ax[4]);
		complet_vlines(ax, img, e);
		if ((ax[2] > 0 && ax[2] < WIDTH) && (ax[3] > 0 && ax[3] < HEIGHT))
		{
			my_mlx_pixel_put(img, ax[2], ax[3], (img->tab)[1][e]);
		}
		inc++;
	}
}

void	horizontal_line(t_data *img, int *ax, int e)
{
	int	inc;

	inc = 0;
	ax[4] = 0;
	while (ax[4] < ax[2] - 1)
	{
		ax[4] = ax[0] + inc;
		ax[5] = ax[1] + inc * (ax[3] - ax[1]) / (ax [2] - ax[0]);
		ax[6] = ax[1] + inc + 1 * (ax[3] - ax[1]) / (ax[2] - ax[0]);
		complet_hlines(ax, img, e);
		if ((ax[4] > 0 && ax[4] < WIDTH) && (ax[5] > 0 && ax[5] < HEIGHT))
		{
			my_mlx_pixel_put(img, ax[4], ax[5], (img->tab)[1][e]);
		}
		inc++;
	}
}

void	complet_hlines(int *ax, t_data *img, int e)
{
	int	x_spread;	
	int	y_spread;
	int	y_axis;

	x_spread = ax[4] - ax[0];
	y_spread = ax[6] - ax[1];
	y_axis = ax[5];
	while (y_spread - x_spread >= 0)
	{
		if ((ax[4] > 0 && ax[4] < WIDTH) && (y_axis > 0 && y_axis < HEIGHT))
			my_mlx_pixel_put(img, ax[4], y_axis, (img->tab)[1][e]);
		y_spread--;
		y_axis++;
	}
	while (y_spread - x_spread <= 0)
	{
		if ((ax[4] > 0 && ax[4] < WIDTH) && (y_axis > 0 && y_axis < HEIGHT))
			my_mlx_pixel_put(img, ax[4], y_axis, (img->tab)[1][e]);
		y_spread++;
		y_axis--;
	}
}

void	complet_vlines(int *ax, t_data *img, int e)
{
	int	x_spread;	
	int	y_spread;
	int	y_axis;

	x_spread = ax[2] - ax[4];
	y_spread = ax[6] - ax[5];
	y_axis = ax[3];
	while (y_spread - x_spread >= 0)
	{
		if ((ax[2] > 0 && ax[2] < WIDTH) && (y_axis > 0 && y_axis < HEIGHT))
			my_mlx_pixel_put(img, ax[2], y_axis, (img->tab)[1][e]);
		y_spread--;
		y_axis++;
	}
	while (y_spread - x_spread <= 0)
	{
		if ((ax[2] > 0 && ax[2] < WIDTH) && (y_axis > 0 && y_axis < HEIGHT))
			my_mlx_pixel_put(img, ax[2], y_axis, (img->tab)[1][e]);
		y_spread++;
		y_axis--;
	}
}
