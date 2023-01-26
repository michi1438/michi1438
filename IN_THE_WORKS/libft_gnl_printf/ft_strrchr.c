/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:56:03 by mguerga           #+#    #+#             */
/*   Updated: 2022/11/07 09:57:43 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = (ft_strlen(s) + 1);
	while (i > 0)
	{
		i--;
		if (s[i] == ((char)(c)))
			return ((char *)(&s[i]));
	}
	return (NULL);
}
