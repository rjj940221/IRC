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

t_clt_env g_clt_env = (t_clt_env) {-1, NULL, NULL, NULL, NULL, NULL, NULL, 0};

void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
	{
		return &(((struct sockaddr_in *) sa)->sin_addr);
	}
	return &(((struct sockaddr_in6 *) sa)->sin6_addr);
}

void loop_connection(struct addrinfo *servinfo)
{
	struct addrinfo *p;
	char s[INET6_ADDRSTRLEN];

	p = servinfo;
	while (p != NULL)
	{
		if (connect(g_clt_env.svr_sock, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(g_clt_env.svr_sock);
			p = p->ai_next;
		} else
			break;
	}
	if (p == NULL)
	{
		wprintw(g_clt_env.winrsp, "client: failed to connect\n");
		close_svr_sock();
	} else
	{
		inet_ntop(p->ai_family, get_in_addr(p->ai_addr),
				  s, sizeof s);
		wprintw(g_clt_env.winrsp, "client: connecting to %s\n", s);
		return_cmd();
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

void input_loop(void)
{
	fd_set readfds;
	fd_set writefds;

	g_clt_env.idx = 0;
	while (1)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		FD_SET(0, &readfds);
		if (g_clt_env.writbuff && g_clt_env.svr_sock != -1)
			FD_SET(g_clt_env.svr_sock, &writefds);
		if (g_clt_env.svr_sock != -1)
			FD_SET(g_clt_env.svr_sock, &readfds);
		Xi(-1, select((g_clt_env.svr_sock == -1) ? 1 : g_clt_env.svr_sock + 1, &readfds, &writefds, NULL, NULL), "select");
		if (FD_ISSET(0, &readfds))
			input_handler(wgetch(g_clt_env.wincmd));
		if (FD_ISSET(g_clt_env.svr_sock, &writefds))
			send_write_buff();
		if (FD_ISSET(g_clt_env.svr_sock, &readfds))
			rcv_data();
	}
}

void initwindow()
{
	int winrow;
	int wincol;

	initscr();
	cbreak();
	noecho();
	refresh();
	getmaxyx(stdscr, winrow, wincol);
	g_clt_env.winrsp = newwin(winrow - 1, wincol, 0, 0);
	g_clt_env.wincmd = newwin(1, wincol, winrow - 1, 0);
	keypad(g_clt_env.wincmd, true);
	scrollok(g_clt_env.wincmd, true);
	scrollok(g_clt_env.winrsp, true);
	wrefresh(g_clt_env.wincmd);
	return_cmd();
}

static void catch_inturupt(int signo)
{
	close_all();
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
	if (signal(SIGWINCH, catch_inturupt) == SIG_ERR)
		ft_print_exit("failed to set up resize catch");
	initwindow();
	if (ac > 1)
	{
		g_clt_env.host = av[1];
		g_clt_env.port = 0;
		if (ac == 3)
			g_clt_env.port = av[2];
		connect_to_server();
	}
	input_loop();
	return (0);
}
