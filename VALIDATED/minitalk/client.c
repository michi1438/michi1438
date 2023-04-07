/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:03:37 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/24 19:10:09 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int ac, char **av)
{
	int					serv_pid;
	int					i;
	struct sigaction	*act;

	if (ac != 3)
		ft_err(ERR_NOT_3_ARG);
	act = malloc(sizeof sigaction);
	set_sigusr(act);
	serv_pid = ft_atoi(av[1]);
	parsing(serv_pid, av);
	send_client_pid(getpid(), serv_pid);
	usleep(100);
	i = 0;
	while (av[2][i] != '\0')
	{
		bitify((int)(av[2][i]), serv_pid);
		i++;
	}
	bitify('\0', serv_pid);
	free(act);
	return (0);
}

void	bitify(int c, int serv_pid)
{
	int	bits;
	int	bit_size;

	bits = 8;
	bit_size = 256;
	while (bits >= 0)
	{
		if ((unsigned char)c >= bit_size)
		{
			protected_kill(serv_pid, SIGUSR1);
			c -= bit_size;
			usleep(100);
		}
		else
		{
			protected_kill(serv_pid, SIGUSR2);
			usleep(100);
		}
		bit_size /= 2;
		bits--;
	}
}

void	parsing(int serv_pid, char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
	{
		if (!(ft_isdigit(av[1][i])))
			ft_err(ERR_NOT_PID);
		i++;
	}
	if (kill(serv_pid, 0) != 0)
		ft_err(ERR_INEXISTANT);
}

void	ft_err(char *err_msg)
{
	ft_printf("Error: %s\n", err_msg);
	exit(0);
}
