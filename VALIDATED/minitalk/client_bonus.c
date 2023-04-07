/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:21:36 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/24 19:50:49 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	protected_kill(int serv_pid, int sig)
{
	if (kill(serv_pid, sig) == -1)
	{
		ft_printf("Error: signal bitify failed, maybe the wrong PID...\n");
		exit(0);
	}
}

void	set_sigusr(struct sigaction *act)
{
	sigemptyset(&act->sa_mask);
	act->sa_flags = 0;
	act->sa_handler = client_confirm;
	sigaction(SIGUSR1, act, NULL);
}

void	client_confirm(int c)
{
	(void)c;
	ft_printf("Server has received :)\n\n");
}

void	send_client_pid(pid_t client_pid, int serv_pid)
{
	int		i;
	char	*str_client_pid;

	str_client_pid = ft_itoa((int)client_pid);
	i = 0;
	while (str_client_pid[i] != '\0')
	{
		bitify(str_client_pid[i], serv_pid);
		i++;
	}
	bitify('\0', serv_pid);
	free(str_client_pid);
}
