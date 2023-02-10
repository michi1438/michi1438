/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:29:51 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/10 17:07:18 by mguerga          ###   ########.fr       */
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
	draw(valcnt, wcount, &img, tab); 
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, interact_mlx, &img);
	mlx_loop(img.mlx);
}

void	fill_sct_hook(int *wcount, int *valcnt, int **tab, t_data *img)
{
	img->valcnt = *valcnt;
	img->wcount = *wcount;
	img->tab = tab;
	ft_printf("%d\n", (img->tab)[0][1]);
}

int	interact_mlx(int keycode, t_data *img)
{
	static int	i;

	//i = 0;
	ft_printf("keycode ; %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	if (keycode == 124)
	{
		i += 20;
		mlx_clear_window(img->mlx, img->win);
		draw(img->valcnt, img->wcount, img, img->tab);
		mlx_put_image_to_window(img->mlx, img->win, img->img, i, 0);
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

void	draw(int valcnt, int wcount, t_data *img, int **tab)
{
	int	i;
	int	j;
	int	e;
	int	axis[2];
	int	scaling;
	
	scaling = to_window_scale(wcount, valcnt);
	e = 0;
	i = valcnt / wcount;
	while (i > 0)
	{
		j = 0;
		while (j < wcount) 
		{	
			if (tab[1][e] == 0)
				tab[1][e] = 0x00FF0000;
			axis[0] = (WIDTH / 2) + (j - i) * scaling;
			axis[1] = (i + j - tab[0][e]) * scaling / sqrt(2); 
			my_mlx_pixel_put(img, axis[0], axis[1], tab[1][e]);
			e++;
			j += 1;
		}
		i -= 1;
	}
}
