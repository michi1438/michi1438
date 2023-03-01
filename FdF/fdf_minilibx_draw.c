/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_minilibx_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:30:27 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/28 23:52:15 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "fdf.h"

void	place_nodes(t_data *img, int *e, int *j, int *i)
{
	int	axis[7];
	float	shortner;
	int	scale;

	scale = img->scaling; 	
	if ((img->tab)[1][*e] == 0)
		(img->tab)[1][*e] = 0x00FF0000;
	axis[0] = ((WIDTH / 2) + img->x_axis) + (*j - *i) * scale;
	shortner = ((float)((img->tab)[0][*e])) * img->accentuate;
	axis[1] = (img->y_axis + (*i + *j - (shortner)) * scale / sqrt(img->x_rot)); 
	axis[4] = ((WIDTH / 2) + img->x_axis) + (*j - (*i + 1)) * scale;
	if (*e + img->wcount < img->valcnt)
		shortner = (float)(img->tab)[0][*e + img->wcount] * img->accentuate;
	axis[5] = (img->y_axis + ((*i + 1 + *j) - shortner) * scale / sqrt(img->x_rot)); 
	if (*i < img->valcnt / img->wcount)
		vertical_line(img, axis, *e);
	(*j)++;
	axis[2] = ((WIDTH / 2) + img->x_axis) + (*j - *i) * scale;
	if (*e + 1 < img->valcnt)
		shortner = (float)(img->tab)[0][*e + 1] * img->accentuate;
	axis[3] = (img->y_axis + (*i + *j - shortner) * scale / sqrt(img->x_rot)); 

	if (*j < img->wcount)
		horizontal_line(img, axis, *e);
}
	
void	vertical_line(t_data *img, int *axis, int e)
{
	int	inc;

	inc = 0;
	axis[2] = 0;
	while (axis[2] < axis[0] - 1)
	{
		axis[2] = axis[4] + inc;
		axis[3] = axis[5] + inc * (axis[1] - axis[5]) / (axis [0] - axis[4]);
		axis[6] = axis[5] + inc + 1 * (axis[1] - axis[5]) / (axis[0] - axis[4]);
		complet_vlines(axis, img, e);
		if ((axis[2] > 0 && axis[2] < WIDTH) && (axis[3] > 0 && axis[3] < HEIGHT))
		{
			my_mlx_pixel_put(img, axis[2], axis[3], (img->tab)[1][e]);
		}
		inc++;
	}
}

void	horizontal_line(t_data *img, int *axis, int e)
{
	int	inc;

	inc = 0;
	axis[4] = 0;
	while (axis[4] < axis[2] - 1)
	{
		axis[4] = axis[0] + inc;
		axis[5] = axis[1] + inc * (axis[3] - axis[1]) / (axis [2] - axis[0]);
		axis[6] = axis[1] + inc + 1 * (axis[3] - axis[1]) / (axis[2] - axis[0]);
		complet_hlines(axis, img, e);
		if ((axis[4] > 0 && axis[4] < WIDTH) && (axis[5] > 0 && axis[5] < HEIGHT))
		{
			my_mlx_pixel_put(img, axis[4], axis[5], (img->tab)[1][e]);
		}
		inc++;
	}
}

void	complet_hlines(int *axis, t_data *img, int e)
{
	int	x_spread;	
	int	y_spread;
	int	Y_axis;

	x_spread = axis[4] - axis[0];
	y_spread = axis[6] - axis[1];
	Y_axis = axis[5];
	while (y_spread - x_spread >= 0)
	{
		if ((axis[4] > 0 && axis[4] < WIDTH) && (Y_axis > 0 && Y_axis < HEIGHT))
			my_mlx_pixel_put(img, axis[4], Y_axis, (img->tab)[1][e]);
		y_spread--;
		Y_axis++;
	}
	while (y_spread - x_spread <= 0)
	{
		if ((axis[4] > 0 && axis[4] < WIDTH) && (Y_axis > 0 && Y_axis < HEIGHT))
			my_mlx_pixel_put(img, axis[4], Y_axis, (img->tab)[1][e]);
		y_spread++;
		Y_axis--;
	}
}

void	complet_vlines(int *axis, t_data *img, int e)
{
	int	x_spread;	
	int	y_spread;
	int	Y_axis;

	x_spread = axis[2] - axis[4];
	y_spread = axis[6] - axis[5];
	Y_axis = axis[3];
	while (y_spread - x_spread >= 0)
	{
		if ((axis[2] > 0 && axis[2] < WIDTH) && (Y_axis > 0 && Y_axis < HEIGHT))
			my_mlx_pixel_put(img, axis[2], Y_axis, (img->tab)[1][e]);
		y_spread--;
		Y_axis++;
	}
	while (y_spread - x_spread <= 0)
	{
		if ((axis[2] > 0 && axis[2] < WIDTH) && (Y_axis > 0 && Y_axis < HEIGHT))
			my_mlx_pixel_put(img, axis[2], Y_axis, (img->tab)[1][e]);
		y_spread++;
		Y_axis--;
	}
}
