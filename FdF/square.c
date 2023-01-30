/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:07:29 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/30 18:01:10 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

int	main(void)
{
	void *mlx;
	void	*mlx_win;
	t_data	img;
	int	i;
	//char	*isfdf;

	i = 5;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	while (i <= 55)
	{
		my_mlx_pixel_put(&img, 5, i, 0x00FF0000);
		my_mlx_pixel_put(&img, i, 5, 0x00FF0000);
		my_mlx_pixel_put(&img, 55, i, 0x00FF0000);
		my_mlx_pixel_put(&img, i, 55, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	int	offset;
	char	*dst;

	offset = (img->line_length * x + (img->bits_per_pixels / 8) * y);
	dst = img->addr + offset;
	*(unsigned int *)dst = color; 
}

/*
	if (ac != 2)
	{
		ft_printf("error, expected 1 arg\n");
		return (0j
	}
	isfdf = ft_strnstr(av[1], ".fdf", 1000); 
	if (isfdf == NULL)
	{
    		ft_printf("error, make sure your arg is a .fdf file\n");	
		return (0);
	}
	return (1);
}*/


