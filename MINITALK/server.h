/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:05:20 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/22 15:28:00 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"

int		g_bit_size = 128;
char	g_client_pid[10];

int		main(void);
void	btoc(int c);
void	set_sigusr(struct sigaction *act1, struct sigaction *act2);

#endif
