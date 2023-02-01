/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:05:31 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/31 15:07:11 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	unsigned int	r;
	int	x;

	r = 0x00000001;
	x = 5;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "this is a gradient");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	while (x <= 1000)
	{
		my_mlx_pixel_put(&img, x, 5, r);
		my_mlx_pixel_put(&img, x, 6, r);
		my_mlx_pixel_put(&img, x, 7, r);
		my_mlx_pixel_put(&img, x, 8, r);
		if (r < 0x000000FF)
			r = r + 0x00000001;
		else if (r < 0x0000FF00)
			r = r + 0x00000100;
		else if (r < 0x00FF0000)
			r = r + 0x00010000;
		else if (r < 0xFF000000)
			r = r + 0x01000000;
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

		

