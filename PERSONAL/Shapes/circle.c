/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:03:24 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/31 14:46:48 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

int	main(void)
{
	void	*mlx;
	void *mlx_win;
	t_data	img;
	int	x;
	int	y;
	int	h;
	
	h = 500;
	y = 0;
	x = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "This is a circle !");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	while (x < h / 2)
	{
		my_mlx_pixel_put(&img, x + h , circlise(x, h), 0x00FF0000);
		my_mlx_pixel_put(&img, circlise(x, h), x + h, 0x00FF0000);
		my_mlx_pixel_put(&img, circlise(x, h), y + h, 0x00FF0000);
		my_mlx_pixel_put(&img, y + h, circlise(x, h),  0x00FF0000);
		my_mlx_pixel_put(&img, circlise_two(x, h) , x + h, 0x00FF0000);
		my_mlx_pixel_put(&img, circlise_two(x, h) , y + h, 0x00FF0000);
		my_mlx_pixel_put(&img, x + h, circlise_two(x, h), 0x00FF0000);
		my_mlx_pixel_put(&img, y + h, circlise_two(x, h), 0x00FF0000);
		x++;
		y--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	circlise(int x, int h)
{
	int	y;

	y = h - sqrt(pow(h / 2, 2) - pow(x, 2));
	return (y);
}

int	circlise_two(int x, int h)
{
	int	y;

	y = h + sqrt(pow(h / 2, 2) - pow(x, 2));
	return (y);
}
