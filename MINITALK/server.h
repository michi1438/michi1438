/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:05:20 by mguerga           #+#    #+#             */
/*   Updated: 2023/03/21 14:21:49 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include "ft_libft_printf_gnl/ft_libft_printf_gnl.h"

int		main(void);
void	set_sigusr(void);
void	btoc(int c);

#endif
