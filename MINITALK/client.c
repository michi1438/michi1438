/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:03:37 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/22 20:10:25 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int ac, char **av)
{
	int					serv_pid;
	int					i;

	if (ac != 3)
		ft_err(ERR_NOT_3_ARG);
	serv_pid = ft_atoi(av[1]);
	parsing(serv_pid, av);
	send_client_pid(getpid(), serv_pid);
	usleep(1000000);
	i = 0;
	while (av[2][i] != '\0')
	{
		bitify((int)(av[2][i]), serv_pid);
		i++;
	}
	bitify('\n', serv_pid);
	return (0);
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
	bitify('\n', serv_pid);
	free(str_client_pid);
}

void	bitify(int c, int serv_pid)
{
	int	bits;
	int	bit_size;

	bits = 7;
	bit_size = 128;
	while (bits >= 0)
	{
		if (c >= bit_size)
		{
			kill(serv_pid, SIGUSR1);
			c -= bit_size;
			usleep(300);
		}
		else
		{
			kill(serv_pid, SIGUSR2);
			usleep(300);
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
