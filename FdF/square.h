
#ifndef FDF_H
# define FDF_H

# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"
# include "minilibx_macos/mlx.h"

typedef struct s_data {
	void	*img;
	char *addr;
	int	bits_per_pixels;
	int	line_length;
	int	endian;
}			t_data;


void	my_mlx_pixel_put(t_data *img, int x, int y, int color);

#endif
