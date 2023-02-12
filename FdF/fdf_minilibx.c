/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:29:51 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/12 18:33:09 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	int	offset;
	char	*dst;

	offset = (img->line_length * y + (img->bits_per_pixels/8) * x);
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

void	start_graph(int wcount, int valcnt, int **tab)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	ft_printf("scale used; %d\n", to_window_scale(wcount, valcnt));
	fill_sct_hook(&wcount, &valcnt, tab, &img);
	draw(valcnt/wcount, &img); 
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, interact_mlx, &img);
	mlx_loop(img.mlx);
}

void	fill_sct_hook(int *wcount, int *valcnt, int **tab, t_data *img)
{
	img->valcnt = *valcnt;
	img->wcount = *wcount;
	img->tab = tab;
	ft_printf("first val of tab ;%d\n", (img->tab)[0][1]);
}

int	interact_mlx(int keycode, t_data *img)
{
	static int	x;
	static int	y;
	static int	zoom;

	ft_printf("keycode ; %d\n", keycode);
	if (keycode == 65307 || keycode == 53) //esc
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	if (keycode == 124 || keycode ==	65363) // right
	{
		x += 20;
		mlx_clear_window(img->mlx, img->win);
		mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
	}
	if (keycode == 45) // minus 
	{
		zoom -= 1;
		mlx_clear_window(img->mlx, img->win);
		mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
	}
	if (keycode == 43) // plus 
	{
		zoom += 1;
		mlx_clear_window(img->mlx, img->win);
		mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
	}	
	if (keycode == 65362) // up
	{
		y -= 20;
		mlx_clear_window(img->mlx, img->win);
		mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
	}
	if (keycode == 65364) // down
	{
		y += 20;
		mlx_clear_window(img->mlx, img->win);
		mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
	}
	if (keycode == 65361) // left
	{
		x -= 20;
		mlx_clear_window(img->mlx, img->win);
		mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
	}
	return (0);
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
	int	axis[2];
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
			axis[0] = (WIDTH / 2) + (j - i) * ogscale;
			axis[1] = (i + j - (img->tab)[0][e]) * ogscale / sqrt(2); 
			my_mlx_pixel_put(img, axis[0], axis[1], (img->tab)[1][e]);
			e++;
			j += 1;
		}
		i -= 1;
	}
}
