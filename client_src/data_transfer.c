/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:15:08 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:22:53 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	add_write_buff(char *data)
{
	g_clt_env.writbuff = ft_strjoin_free_l(g_clt_env.writbuff, data);
}

void	send_write_buff(void)
{
	size_t	size;
	char	*tmp;
	long	re;

	size = (ft_strlen(g_clt_env.writbuff) < BUF_SIZE) ?
		ft_strlen(g_clt_env.writbuff) : BUF_SIZE;
	tmp = g_clt_env.writbuff;
	re = XL(-1, send(g_clt_env.svr_sock, tmp, size, 0), "send");
	if (re > 0)
	{
		g_clt_env.writbuff = ft_strsub(g_clt_env.writbuff,
				(unsigned int)re, size - re);
		ft_strdel(&tmp);
	}
}

void	rcv_data(void)
{
	ssize_t	r;
	char	buf[BUF_SIZE + 1];
	char	*cmd;

	r = recv(g_clt_env.svr_sock, buf, BUF_SIZE, 0);
	if (r <= 0)
	{
		close_svr_sock();
		wprintw(g_clt_env.winrsp, "lost server connection\n");
		return_cmd();
	}
	else
	{
		buf[r] = '\0';
		g_clt_env.readbuff = ft_strjoin_free_l(g_clt_env.readbuff, buf);
		while ((cmd = get_cmd(&g_clt_env.readbuff)) != NULL)
		{
			wprintw(g_clt_env.winrsp, "%s\n", cmd);
			return_cmd();
			ft_strdel(&cmd);
		}
	}
}
