/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:03:37 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/21 21:25:19 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	int	i;

	i = 0;
	ft_printf("Server pid :%d\n", getpid());
	set_sigusr();
	while (i == 0)
		;
	return (0);
}

void	set_sigusr(void)
{
	struct sigaction	*act1;
	struct sigaction	*act2;

	act1 = malloc(sizeof(sigaction));
	act2 = malloc(sizeof(sigaction));
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
	static int			ch;

	if (i <= 8)
	{
		if (c == 10)
			ch += g_bit_size;
		g_bit_size /= 2;
		i++;
	}
	if (i == 8)
	{
		write(1, &ch, 1);
		i = 0;
		g_bit_size = 128;
		ch = 0;
	}
}
