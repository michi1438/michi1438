/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:17:06 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/31 17:01:57 by mguerga          ###   ########.fr       */
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

char	*replace_nline(int fd, char *nline)
{
	char	*nptr;

	nptr = get_next_line(fd);
	free (nline);
	return (nptr);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], fd);
}
