#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define S 1024

int maxfds, cnt, ids[S];
char *msgs[S], rbuf[S], wbuf[S];
fd_set rfds, wfds, afds;

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void notif(int except, char *str)
{
	for (int fd = 0; fd <= maxfds; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != except)
			send(fd, str, strlen(str), 0);
	}
}

void send_msg(int fd)
{
	char *msg;

	while (extract_message(&(msgs[fd]), &msg))
	{
		sprintf(wbuf, "client %d: ", ids[fd]);
		notif(fd, wbuf);
		notif(fd, msg);
		free(msg);
	}
}


void add_cli(int fd)
{
	ids[fd] = cnt++;
	if (fd > maxfds)
		maxfds = fd;
	FD_SET(fd, &afds);
	msgs[fd] = NULL;
	sprintf(wbuf, "server: client %d just arrived\n", ids[fd]);
	notif(fd, wbuf);
}

void rm_cli(int fd)
{
	FD_CLR(fd, &afds);
	sprintf(wbuf, "server: client %d just left\n", ids[fd]);
	notif(fd, wbuf);
}

void rror()
{
	write (2, "Fatal error\n", 12);
	exit(1);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	int sockfd;
	struct sockaddr_in servaddr;

	FD_ZERO(&afds);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		rror();
	maxfds = sockfd;
	FD_SET(sockfd, &afds);
	bzero(&servaddr, sizeof(servaddr)); 

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));
  
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		rror();
	if (listen(sockfd, 10) != 0)
		rror();

	while (1)
	{
		rfds = wfds = afds;
		if (select(maxfds + 1, &rfds, &wfds, NULL, NULL) < 0)
			rror();
		for(int fd = 0; fd <= maxfds; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue;
			if (fd == sockfd)
			{
				fd = accept(sockfd, NULL, NULL);
				if (fd >= 0)
				{
					add_cli(fd);
					break;
				}
			}
			else
			{
				int bytes = recv(fd, wbuf, 1000, 0);
				if (bytes <= 0)
				{
					rm_cli(fd);
					break;
				}
				wbuf[bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], wbuf);
				send_msg(fd);
			}
		}
	}
	return(0);
}
