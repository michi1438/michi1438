/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:29:51 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/01 10:40:09 by mguerga          ###   ########.fr       */
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
	fill_sct_hook(&wcount, &valcnt, tab, &img);
	draw(valcnt/wcount, &img); 
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, keyboard_mlx, &img);
	mlx_hook(img.win, 4, 1L<<2, button_mlx, &img);
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
	
	e = (i - 1) * img->wcount;
	while (i > 0)
	{
		e = (i - 1) * img->wcount;
		j = 0;
		while (j < img->wcount) 
		{	
			place_nodes(img, &e, &j, &i);
			e++;
		}
		i--;
	}
}
