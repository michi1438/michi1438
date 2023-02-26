/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:29:51 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/25 21:15:08 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	int	offset;
	char	*dst;

	offset = (img->line_length * y + (img->bpp/8) * x);
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

void	start_graph(int wcount, int valcnt, int **tab)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	ft_printf("scale used; %d\n", to_window_scale(wcount, valcnt));
	fill_sct_hook(&wcount, &valcnt, tab, &img);
	draw(valcnt/wcount, &img); 
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, interact_mlx, &img);
	mlx_loop(img.mlx);
}

int	to_window_scale(int wcount, int valcnt)
{
	int	scale_to_width;
	int	scale_to_height;

	scale_to_width = WIDTH / wcount / 2;
	scale_to_height = HEIGHT / ((valcnt / wcount) + 1) / 2;
	if (scale_to_width < scale_to_height)
		return (scale_to_width);
	else
		return (scale_to_height);
}

void	draw(int i, t_data *img)
{
	int	j;
	int	e;
	int	axis[7];
	int	ogscale;
	
	ogscale = to_window_scale(img->wcount, img->valcnt);
	e = 0;
	while (i > 0)
	{
		j = 0;
		while (j < img->wcount) 
		{	
			if ((img->tab)[1][e] == 0)
				(img->tab)[1][e] = 0x00FF0000;
			axis[0] = ((WIDTH / 2) + img->x_axis) + (j - i) * (ogscale + img->scaling);
			axis[1] = (img->y_axis + (i + j - (img->tab)[0][e]) * (ogscale + img->scaling) / sqrt(2)); 
			axis[4] = ((WIDTH / 2) + img->x_axis) + (j - (i - 1)) * (ogscale + img->scaling);
			axis[5] = (img->y_axis + (((i - 1) + j) - (img->tab)[0][e]) * (ogscale + img->scaling) / sqrt(2)); 
			j++;
			axis[2] = ((WIDTH / 2) + img->x_axis) + (j - i) * (ogscale + img->scaling);
			axis[3] = (img->y_axis + (i + j - (img->tab)[0][e + 1]) * (ogscale + img->scaling) / sqrt(2)); 
			//vertical_line(img, axis, e);
			horizontal_line(img, axis, e);
			e++;
		}
		i -= 1;
	}
}

void	vertical_line(t_data *img, int *axis, int e)
{
	int	inc;

	inc = 0;
	while (axis[5] < axis[1])
	{
		axis[5] = axis[5] + inc;
		//complet_lines();
		if ((axis[4] > 0 && axis[4] < WIDTH) && (axis[5] > 0 && axis[5] < HEIGHT))
		{
			my_mlx_pixel_put(img, axis[4], axis[5], (img->tab)[1][e]);
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
		complet_lines(axis, img, e);
		if ((axis[4] > 0 && axis[4] < WIDTH) && (axis[5] > 0 && axis[5] < HEIGHT))
		{
			my_mlx_pixel_put(img, axis[4], axis[5], (img->tab)[1][e]);
		}
		inc++;
	}
}


void	complet_lines(int *axis, t_data *img, int e)
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
