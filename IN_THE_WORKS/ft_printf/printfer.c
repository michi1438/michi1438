/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:26:02 by mguerga           #+#    #+#             */
/*   Updated: 2022/12/19 13:10:06 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	perc;
	t_conv	*cvut;
	int		ret[1];

	ret[0] = 0;
	i = 0;
	va_start(perc, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cvut = create_cvut(str, i, cvut);
			i = placeva(ret, cvut, i, perc);
			free(cvut);
		}
		else
		{
			ft_putchar_fd(str[i++], 1);
			ret[0]++;
		}
	}
	va_end(perc);
	return (ret[0]);
}

int	testperc(t_conv *cvut)
{
	ft_putchar_fd('%', 1);
	cvut->len = 1;
	return (1);
}

int	placeva(int *ret, t_conv *cvut, int i, va_list perc)
{
	if (cvut->type == '%')
		i += testperc(cvut);
	else if (cvut->type == 'c')
		i += printargcha(va_arg(perc, int), cvut);
	else if (cvut->type == 's')
		i = ptrtypes(cvut, va_arg(perc, void *), i);
	else
		i = numbertypes(cvut, va_arg(perc, long long), i);
	ret[0] += cvut->len;
	return (i);
}

int	ptrtypes(t_conv *cvut, void *toconv, int i)
{
	if (cvut->type == 's')
	{
		if (toconv == NULL)
		{
			cvut->len += 6;
			i += testprintargstr("(null)", cvut);
		}
		else
		{
			cvut->len = ft_strlen((const char *) toconv);
			i += testprintargstr((const char *) toconv, cvut);
		}
	}
	return (i);
}
