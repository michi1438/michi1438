/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:52:48 by mguerga           #+#    #+#             */
/*   Updated: 2023/01/26 11:59:45 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = ft_calloc(sizeof(char), (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (ptr == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen_gnl(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*freedom(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*freeandreplace(char *oldstr, char *stradd, int ind)
{
	char	*nptr;

	if (ind >= 0)
	{
		nptr = ft_strjoin_gnl("", &stradd[ind + 1]);
		oldstr = freedom(oldstr); 
		return (nptr);
	}
	else
	{
		nptr = ft_strjoin_gnl(oldstr, stradd);
		oldstr = freedom(oldstr);
		return (nptr);
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((char *)(ptr))[i] = '\0';
		i++;
	}
	return (ptr);
}

int	readforterm(char *buf, int toggle)
{
	int	i;

	i = 0;
	if (toggle == 1)
	{
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				return (i);
			i++;
		}
		return (-1);
	}
	else
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (buf[i] == '\n' || buf[i] == '\0')
				return (i);
			i++;
		}
		return (-1);
	}
}
