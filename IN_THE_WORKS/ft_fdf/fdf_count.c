/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:34:07 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/28 22:49:07 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_count(int fd)
{
	int		red;
	int		i;
	char	buf[1];

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
	return (i);
}

int	word_count(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL && splited[i][0] != '\n')
	{
		i++;
	}
	clean(splited);
	return (i);
}

void	clean(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

int	lonely_ret_count(int fd)
{
	int		i;
	char	buf[1];

	i = 0;
	while (read(fd, buf, 1) != 0)
	{
		if (buf[0] == ' ')
		{
			read(fd, buf, 1);
			if (buf[0] == '\n')
				i++;
		}
	}
	return (i);
}
