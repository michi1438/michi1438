/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:59:45 by mguerga           #+#    #+#             */
/*   Updated: 2023/10/24 11:07:37 by mguerga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int ft_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	return (i);
}

size_t ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int nbr_of_word(char **argv)
{
	int i = 1;
	while (argv[i] != NULL)
		i++;
	return (i);
}
	
int	cmd_pipes_ratio(int *n_pipes, int *n_cmd)
{
	if (*n_pipes + 1 == *n_cmd)
		return (0);
	else
	{
		ft_putstr("err; n_cmd does'nt fit the number of pipes! \n");
		*n_pipes = 0;
		*n_cmd = 0;
		return (1);
	}
}

int	exec_wrap(char ***cmds, char **env, int *n_cmd, int *n_pipes)
{
	int i;
	int fd[2];

	i = 0;
	if (pipe(fd) == -1)
		perror("pipe");
	printf("fd[0] = %d\n", fd[0]);
	printf("fd[1] = %d\n", fd[1]);
	while (i < *n_cmd)
	{
		if (*n_cmd > 1)
			dup2(fd[1], fd[0]);	
		if (fork() == 0)
		{
			execve(cmds[i][0], cmds[i], env);
			perror("execve");
		}	//interpret and free cmds up to here... 
		i++;
	}
	*n_cmd = 0;
	*n_pipes = 0;
	return (0);
}

int main(int ac, char **av, char **env)
{
	int i = 1;
	int y = 0;
	int e = 0;
	int ret = 0;
	int n_pipes = 0;
	int n_cmd = 0;
	char ***cmds = malloc(sizeof(char **) * ac);

	if (ac == 1)
		return (0);
	while (av[i] != NULL)
	{
		if (strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		{
			n_cmd++;
			cmds[e] = malloc(sizeof(char *) * 10);
			while (av[i] != NULL && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
			{
				cmds[e][y] = malloc(sizeof(char) * ft_strlen(av[i]));
				cmds[e][y++] = av[i++];
			}
			cmds[e][y] = NULL;
			e++;
			y = 0;
		}
		if (av[i] == NULL)
			break ;
		if (strcmp(av[i], ";") == 0)
		{
			ret = cmd_pipes_ratio(&n_pipes, &n_cmd);
			if (ret != 0)
				return (ret);
			e = 0;
			exec_wrap(cmds, env, &n_cmd, &n_pipes);
		}
		if (strcmp(av[i], "|") == 0)
		{
			n_pipes++;
		}
	
		i++;
	}
	if (n_cmd != 0)
		ret = cmd_pipes_ratio(&n_pipes, &n_cmd);
	if (ret != 0)
		return (ret);
	exec_wrap(cmds, env, &n_cmd, &n_pipes);
	//interpret and free cmds up to here... 
	return (0);
}
