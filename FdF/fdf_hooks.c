/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:00:43 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/06 14:01:11 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_sct_hook(int *wcount, int *valcnt, int **tab, t_data *img)
{
	img->valcnt = *valcnt;
	img->wcount = *wcount;
	img->tab = tab;
	img->scaling = 0;
	img->x_axis = 0;
	img->accentuate = 1;
	img->scaling = to_window_scale(img->wcount, img->valcnt);
	img->y_axis = calc_offelev(img);
}

void	redo_img(t_data *img, int x, int y, int zoom)
{
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endi);
	img->scaling = to_window_scale(img->wcount, img->valcnt) + zoom;
	img->x_axis = x;
	img->y_axis = y + calc_offelev(img);
	draw(img->valcnt / img->wcount, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	calc_offelev(t_data	*img)
{
	int	delta;
	int	i;
	int	tot;

	tot = 0;
	i = 0;
	delta = img->wcount / 10;
	while (i < img->valcnt)
	{
		tot += img->tab[0][i];
		i += delta;
	}
	return (tot / (img->valcnt / delta));
}
