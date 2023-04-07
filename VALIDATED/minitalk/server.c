/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:03:37 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/24 19:33:55 by mguerga          ###   ########.fr       */
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
		pause();
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
	static t_s_btoc		count;

	if (count.i++ != -10 && c == SIGUSR1)
		count.ch += g_bit_size;
	g_bit_size /= 2;
	if (count.i == 9 && count.flg_clt_pid == 0)
	{
		if ((char)count.ch == '\0')
		{
			count.client_pid[count.y] = '\0';
			count.y = 0;
			count.flg_clt_pid = 1;
		}
		else
			count.client_pid[count.y++] = (char)count.ch;
		count = re_init(count);
	}
	else if (count.i == 9)
	{
		count.ch = (char)count.ch;
		if ((char)count.ch == '\0')
			count = protected_clt_kill(count);
		write(1, &(count.ch), 1);
		count = re_init(count);
	}
}

t_s_btoc	re_init(t_s_btoc count)
{
	count.i = 0;
	count.ch = 0;
	g_bit_size = 256;
	return (count);
}

t_s_btoc	protected_clt_kill(t_s_btoc count)
{
	if (kill(ft_atoi(count.client_pid), SIGUSR1) == -1)
	{
		ft_printf("confirmation signal failed !\n");
		exit(0);
	}
	count.flg_clt_pid = 0;
	count.ch = '\n';
	return (count);
}
