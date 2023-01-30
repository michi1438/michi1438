/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printparser_supl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:11:24 by xbeheydt          #+#    #+#             */
/*   Updated: 2023/01/26 11:48:22 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft_printf_gnl.h"

int	proxylengthcnt(const char *str, int i)
{
	int	cnt;

	cnt = 1;
	while (!(ft_isalpha(str[i])) && str[i++] != '%')
		cnt++;
	return (cnt);
}
