/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:41:34 by rojones           #+#    #+#             */
/*   Updated: 2017/07/13 14:20:07 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

t_clt_env g_clt_env = (t_clt_env) {-1, NULL, 0};

void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

void	loop_connection(struct addrinfo *servinfo)
{
	struct addrinfo *p;
	char 			s[INET6_ADDRSTRLEN];

	p = servinfo;
	while (p != NULL)
	{
		if (connect(g_clt_env.svr_sock, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(g_clt_env.svr_sock);
			perror("client: connect");
			p = p->ai_next;
		} else
			break;
	}
	if (p == NULL)
		fprintf(stderr, "client: failed to connect\n");
	else
	{
		inet_ntop(p->ai_family, get_in_addr(p->ai_addr),
				  s, sizeof s);
		printf("client: connecting to %s\n", s);
	}
}

void connect_to_server(void)
{
	struct addrinfo hints;
	struct addrinfo *servinfo;

	int rv;

	if (!g_clt_env.host)
		return;
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	g_clt_env.port = (g_clt_env.port) ? g_clt_env.port : "tcp";
	if ((rv = getaddrinfo(g_clt_env.host, g_clt_env.port, &hints, &servinfo)) != 0)
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		exit(1);
	}
	g_clt_env.svr_sock = ipv4();
	loop_connection(servinfo);
	freeaddrinfo(servinfo);
}

/*
void		ft_process_rsp(t_cmd_rsp rsp)
{
	if (rsp.code >= 200 && rsp.code < 300)
		printf("\x1b[32mSUCCESS(%d):\x1b[0m %s\n", rsp.code, rsp.msg);
	if (rsp.code >= 300 && rsp.code < 400)
		printf("\x1b[33mPENDING(%d):\x1b[0m %s\n", rsp.code, rsp.msg);
	if (rsp.code >= 400 && rsp.code < 600)
		printf("\x1b[31mERROR(%d):\x1b[0m %s\n", rsp.code, rsp.msg);
}
*/

void input_loop(void)
{
	char *line;

	while (1)
	{
		get_next_line(0, &line);
		search_builin(line);
		free(line);
	}
}

static void catch_inturupt(int signo)
{
	printf("SIGNAL: %d\n", signo);
	//ft_quit(NULL);
	exit(1);
}

int main(int ac, char **av)
{
	if (ac > 3 || (ac == 3 && check_port(av[2]) == -1))
	{
		printf("incorrect parameters please use '%s [<hostname> "
					   "[<port>]]'\n\te.g. %s localhost 8080", av[0], av[0]);
		exit(1);
	}
	if (signal(SIGINT, catch_inturupt) == SIG_ERR)
		ft_print_exit("failed to set up interrupt catch");
	g_clt_env.svr_sock = ipv4();
	if (ac > 1)
	{
		g_clt_env.host = av[1];
		g_clt_env.port = 0;
		if (ac == 3)
			g_clt_env.port = av[2];
		connect_to_server();
	}
	input_loop();
}
