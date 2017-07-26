/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:41:34 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:59:06 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

t_clt_env g_clt_env = (t_clt_env) {-1, NULL, NULL, NULL, NULL, NULL, NULL, 0};

void		input_loop(void)
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
		XI(-1, select((g_clt_env.svr_sock == -1) ? 1 : g_clt_env.svr_sock + 1
				, &readfds, &writefds, NULL, NULL), "select");
		if (FD_ISSET(0, &readfds))
			input_handler(wgetch(g_clt_env.wincmd));
		if (g_clt_env.svr_sock != -1)
		{
			if (FD_ISSET(g_clt_env.svr_sock, &writefds))
				send_write_buff();
			if (FD_ISSET(g_clt_env.svr_sock, &readfds))
				rcv_data();
		}
	}
}

static void	catch_inturupt(int signo)
{
	signo++;
	close_all();
	exit(1);
}

int			main(int ac, char **av)
{
	if (ac > 3 || (ac == 3 && check_port(av[2]) == -1))
	{
		printf("incorrect parameters please use '%s [<hostname> "
				"[<port>]]'\n\te.g. %s localhost 8080", av[0], av[0]);
		exit(1);
	}
	if (signal(SIGINT, catch_inturupt) == SIG_ERR)
		print_err_exit("signal", __FILE__, __LINE__,
				"failed to set up interrupt catch");
	if (signal(SIGWINCH, catch_inturupt) == SIG_ERR)
		print_err_exit("signal", __FILE__, __LINE__,
				"failed to set up resize catch");
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
