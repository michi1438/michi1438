/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:28 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/08 19:46:27 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int	fd;
	int	lines;
	int	lonely_ret;

	if (fdf_parser(ac, av) == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	lonely_ret = lonely_ret_count(fd);
	fd = open(av[1], O_RDONLY);
	lines = line_count(fd);
	fd = open(av[1], O_RDONLY);
	ft_putlineto_tab(fd, lines, lonely_ret);
	return (1);
}

int	ft_putlineto_tab(int fd, int lines, int lonely_ret)
{
	int		x;
	int		valcnt;
	int		*tab[2];
	int		wcount;
	char	*nline;

	valcnt = 0;
	nline = get_next_line(fd);
	wcount  = word_count(ft_split(nline, ' '));
	tab[0] = malloc(lines * sizeof(int) * wcount);
	tab[1] = malloc(lines * sizeof(int) * wcount);
	while (nline != NULL)
	{
		x = 0;
		while (ft_split(nline, ' ')[x] != NULL)
		{
			if (contain_nonnum(ft_split(nline, ' ')[x]) == 2)
				ft_err(ER_NONUM);
			if (contain_nonnum(ft_split(nline, ' ')[x]) == 1)
			{
				tab[0][valcnt] = ft_atoi(ft_split(ft_split(nline, ' ')[x], ',')[0]);
				tab[1][valcnt++] = ft_atohex(ft_split(ft_split(nline, ' ')[x], ',')[1]);
			}
			else if (ft_split(nline, ' ')[x][0] != '\n')
			{	
				tab[0][valcnt] = ft_atoi(ft_split(nline, ' ')[x]);
				tab[1][valcnt++] = 0;
			}
			x++;
		}	
		nline = replace_nline(fd, nline);
	}
	free(nline);
	ft_printf("splt_sz; %d\ntot_sz; %d\nmal_sz; %d\nlon_ret; %d\n", x, valcnt, lines * x - lonely_ret, lonely_ret);
	if (valcnt % (x - lonely_ret) != 0)
		ft_err(ER_RECT);
	enum_tab(tab[0], valcnt, x - (lonely_ret/lines));
	ft_printf("\n");
	enum_tab(tab[1], valcnt, x - (lonely_ret/lines));
	start_graph(wcount, valcnt);
	return (fd);
}

void ft_err(char *err)
{
	perror(err);
	exit(1);
}

void	start_graph(int wcount, int valcnt)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	i;
	int	j;

	printf("%d%d\n", wcount, valcnt);
	i = valcnt / wcount;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	while (i > 0)
	{
		j = 0;
		while (j < wcount) 
		{	
			my_mlx_pixel_put(&img, (WIDTH / 2) + (j - i) * 10, (HEIGHT / 2) + (i + j) * 10, 0x00FF0000);
			j += sqrt(2);
		}
		i -= sqrt(2) / 2;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
