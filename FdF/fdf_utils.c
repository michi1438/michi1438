/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:33:13 by mguerga           #+#    #+#             */
/*   Updated: 2023/02/28 17:54:36 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*replace_nline(int fd, char *nline)
{
	char	*nptr;

	nptr = get_next_line(fd);
	free (nline);
	return (nptr);
}

int	contain_nonnum(char *word)
{
	int	i;

	i = 0;
	while (ft_isdigit(word[i]) || word[i] == '-')
		i++;
	if (word[i] == '\0' || word[i] == '\n')
		return (0);
	else if (word[i] == ',')
		return (1);
	else
		return (2);
}

int	calchex(int i, const char *nptr);
int	trimatohex(const char *nptr, int *neg);
int	ft_ishex(int c);

unsigned int	ft_atohex(char *nptr)
{
	int	neg[2];
	int	i;

	neg[0] = 1;
	if (nptr[0] == '0' && nptr[1] == '\0')
		return (0);
	if (!(ft_ishex(nptr[0])))
	{
		i = trimatohex(nptr, neg);
		if (i == 0)
			return (0);
	}
	else
		i = 0;
	i += 2;
	while (ft_ishex(nptr[i]))
		i++;
	i--;
	return (calchex(i, nptr) * neg[0]);
}	

int	calchex(int i, const char *nptr)
{
	int	mult;
	int	res;

	res = 0;
	mult = 1;
	while (i >= 0 && ft_ishex(nptr[i]))
	{
		if (ft_isdigit(nptr[i]))
			res += (nptr[i] - 48) * mult;
		else
			res += (nptr[i] - 55) * mult; 
		mult *= 16;
		i--;
	}
	return (res);
}

int	trimatohex(const char *nptr, int *neg)
{
	int		i;
	int		j;
	char	n[2];

	i = 0;
	j = 0;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	while (!(ft_ishex(nptr[i])))
	{
		i++;
		j++;
	}
	n[0] = nptr[i - 1];
	if (j > 1 || ((j == 1) && ((!(ft_isprint(n[0]))) || (ft_isalpha(n[0])))))
		return (0);
	if (nptr[i - 1] == '-')
		neg[0] = -1;
	return (i);
}

int	ft_ishex(int c)
{
	char *hexval;	
	int	i;

	i = 0;
	hexval = "0123456789ABCDEF";
	while (hexval[i] != '\0')
	{
		if (hexval[i] == c)
			return (1);
		i++;
	}
	return (0);
}
