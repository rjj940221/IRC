/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:19:55 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:25:41 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

int		check_port(const char *str)
{
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (-1);
		str++;
	}
	return (1);
}

void	close_svr_sock(void)
{
	close(g_clt_env.svr_sock);
	g_clt_env.svr_sock = -1;
}

void	return_cmd(void)
{
	wmove(g_clt_env.wincmd, 0, (int)g_clt_env.idx);
	wrefresh(g_clt_env.winrsp);
	wrefresh(g_clt_env.wincmd);
}

void	close_ncurses(void)
{
	if (g_clt_env.winrsp)
	{
		wattroff(g_clt_env.winrsp, COLOR_PAIR(1));
		delwin(g_clt_env.winrsp);
	}
	if (g_clt_env.wincmd)
	{
		wattroff(g_clt_env.wincmd, COLOR_PAIR(1));
		delwin(g_clt_env.wincmd);
	}
	g_clt_env.wincmd = NULL;
	g_clt_env.winrsp = NULL;
	endwin();
	endwin();
}

void	close_all(void)
{
	ft_strdel(&g_clt_env.readbuff);
	ft_strdel(&g_clt_env.writbuff);
	close_svr_sock();
	close_ncurses();
}
