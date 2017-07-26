/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 09:57:38 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:21:16 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	*get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET)
	{
		return (&(((struct sockaddr_in *)sa)->sin_addr));
	}
	return (&(((struct sockaddr_in6 *)sa)->sin6_addr));
}

void	loop_connection(struct addrinfo *servinfo)
{
	struct addrinfo	*p;
	char			s[INET6_ADDRSTRLEN];

	p = servinfo;
	while (p != NULL)
	{
		if (connect(g_clt_env.svr_sock, p->ai_addr, p->ai_addrlen) == -1)
		{
			close(g_clt_env.svr_sock);
			p = p->ai_next;
		}
		else
			break ;
	}
	if (p == NULL)
	{
		wprintw(g_clt_env.winrsp, "client: failed to connect\n");
		close_svr_sock();
	}
	else
	{
		inet_ntop(p->ai_family, get_in_addr(p->ai_addr), s, sizeof(s));
		wprintw(g_clt_env.winrsp, "client: connecting to %s\n", s);
	}
	return_cmd();
}

void	connect_to_server(void)
{
	struct addrinfo	hints;
	struct addrinfo	*servinfo;
	int				rv;
	struct protoent	*pt;

	pt = (struct protoent*)XV(NULL,
			getprotobyname("tcp"), "failed to get protocol");
	if (!g_clt_env.host)
		return ;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = pt->p_proto;
	g_clt_env.port = (g_clt_env.port) ? g_clt_env.port : "irc";
	if ((rv = getaddrinfo(g_clt_env.host, g_clt_env.port, &hints, &servinfo))
		!= 0)
	{
		close_all();
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		exit(1);
	}
	g_clt_env.svr_sock = ipv4();
	loop_connection(servinfo);
	freeaddrinfo(servinfo);
}

void	initwindow(void)
{
	int winrow;
	int wincol;

	initscr();
	start_color();
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
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	color_set(1, NULL);
}
