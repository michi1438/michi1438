/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_n_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:32:48 by mguerga           #+#    #+#             */
/*   Updated: 2023/04/05 12:17:28 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*_trimer(char *val, int *neg);

int	atoi_n_check(char *val)
{
	int			i;
	long int	res;
	int			neg;
	long int	mult;

	mult = 1;
	neg = 1;
	res = 0;
	val = _trimer(val, &neg);
	i = ft_strlen(val) - 1;
	while (i >= 0)
	{
		if (!(ft_isdigit(val[i])))
			ft_err();
		res += (val[i] - 48) * mult;
		mult *= 10;
		i--;
	}
	if (res == 2147483648 && neg == -1)
		return (res * neg);
	if (res < INT_MIN || res > INT_MAX)
		ft_err();
	return (res * neg);
}

char	*_trimer(char *val, int *neg)
{
	int	i;

	i = 0;
	while (val[i] > 7 && val[i] < 15 && val[i] == ' ')
		i++;
	while (val[i] == '+' || val[i] == '-')
	{
		if (val[i + 1] == '-' || val[i + 1] == '+')
			ft_err();
		if (val[i] == '-')
			*neg = -1;
		i++;
	}
	if (val[i] == '\0')
		ft_err();
	return (&val[i]);
}
