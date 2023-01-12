/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:51:04 by mguerga           #+#    #+#             */
/*   Updated: 2022/10/28 16:41:49 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_set_occurence(char const *s1, char const *set);

char *ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	ind;
	char	*ptr;

	i = 0;
	ind = 0;
	ptr = malloc(ft_strlen(s1) - count_set_occurence(s1, set) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0' && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
		{
			ptr[ind] = s1[i];
			ind++;
		}
		i++;
	}
	ptr[ft_strlen(s1) - count_set_occurence(s1, set) + 1] = '\0';
	return (ptr);
}

int	count_set_occurence(char const *s1, char const *set)
{
	int	i;
	int	j;
	int count;
	
	i = 0;
	j = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		if
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}





