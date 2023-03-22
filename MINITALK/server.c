/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:03:37 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/22 15:49:54 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	int					i;
	struct sigaction	*act1;
	struct sigaction	*act2;

	act1 = malloc(sizeof(sigaction));
	act2 = malloc(sizeof(sigaction));
	i = 0;
	ft_printf("Server pid :%d\n", getpid());
	set_sigusr(act1, act2);
	while (i == 0)
		;
	free(act1);
	free(act2);
	return (0);
}

void	set_sigusr(struct sigaction *act1, struct sigaction *act2)
{
	sigemptyset(&act1->sa_mask);
	act1->sa_flags = 0;
	act1->sa_handler = btoc;
	sigaction(SIGUSR1, act1, NULL);
	sigemptyset(&act2->sa_mask);
	act2->sa_flags = 0;
	act2->sa_handler = btoc;
	sigaction(SIGUSR2, act2, NULL);
}	

void	btoc(int c)
{
	static int			i;
	static int			y;
	static int			ch;
	static int			flg_clt_pid;

	if (i <= 8)
	{
		if (c == 10)
			ch += g_bit_size;
		g_bit_size /= 2;
		i++;
	}
	if (i == 8)
	{
		if (flg_clt_pid == 0)
		{
			if ((char)ch == '\n')
			{
				g_client_pid[y] = '\0';
				kill(ft_atoi(g_client_pid), SIGUSR1);
				flg_clt_pid = 1;
			}
			g_client_pid[y] = (char)ch;
			i = 0;
			ch = 0;
			g_bit_size = 128;
			y++;
		}
		else
		{
			write(1, &ch, 1);
			i = 0;
			g_bit_size = 128;
			ch = 0;
		}
	}
}
