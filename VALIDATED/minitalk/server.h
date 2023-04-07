/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:05:20 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/24 19:28:15 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"

int		g_bit_size = 256;

typedef struct s_s_btoc{
	int		i;
	int		y;
	int		ch;
	int		flg_clt_pid;
	char	client_pid[100];
}	t_s_btoc;

int			main(void);
void		btoc(int c);
void		set_sigusr(struct sigaction *act1, struct sigaction *act2);
t_s_btoc	protected_clt_kill(t_s_btoc count);
t_s_btoc	re_init(t_s_btoc count);

#endif
