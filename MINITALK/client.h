/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:05:20 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/21 14:14:34 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define ERR_NOT_3_ARG "must have 3 args: ./client [server pid] [message]"
# define ERR_NOT_PID "first arg must be a PID: ./client [server pid] [message]"
# define ERR_INEXISTANT "the given PID doesn't exist"

# include <unistd.h>
# include <signal.h>
# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"

int		main(int ac, char **av);
void	ft_err(char *err_msg);
void	set_sigusr(struct sigaction *act);
void	*print_in_server(int useless);
void	parsing(int serv_pid, int ac, char **av);
void	bitify(int c, int serv_pid);

#endif