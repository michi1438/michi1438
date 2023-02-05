/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:34:07 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/05 18:46:46 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_count(int fd)
{
	int		i;
	char	buf[1];
	int	red;

	i = 0;
	red = read(fd, buf, 1);
	while (red > 0)
	{
		if (buf[0] == '\n')
			i++;
		if (buf[0] != '\n')
		{
			red = read(fd, buf, 1);
			if (red == 0)
				i++;
		}
		else
			red = read(fd, buf, 1);
	}
	ft_printf("line_count; %d\n", i);
	return (i);
}

int	koma_count(int fd)
{
	int		i;
	char	buf[1];

	i = 0;
	while (read(fd, buf, 1) != 0)
		if (buf[0] == ',')
			i++;
	ft_printf("koma_count; %d\n", i);
	return (i);
}

int	word_count(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL && splited[i][0] != '\n')
		i++;
	ft_printf("word_count; %d\n", i);
	return (i);
}

int	lonely_ret_count(int fd)
{
	int		i;
	char	buf[1];

	i = 0;
	while (read(fd, buf, 1) != 0)
		if (buf[0] == ' ')
		{
			read(fd, buf, 1);
			if (buf[0] == '\n')
				i++;
		}
	ft_printf("lonely_ret_count; %d\n", i);
	return (i);
}
