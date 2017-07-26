/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:23:17 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:45:42 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	search_cmd(t_env *env, char *cmd, int sock)
{
	char	**tav;
	int		cidx;
	size_t	gidx;

	tav = split_cmd(cmd);
	cidx = (tav[0][0] == ':') ? 1 : 0;
	gidx = 0;
	while (g_cmds[gidx].name)
	{
		if (ft_strcmp(g_cmds[gidx].name, tav[cidx]) == 0)
		{
			(*g_cmds[gidx].fnc)(env, &tav[cidx], sock);
			ft_strarrdel(&tav);
			return ;
		}
		gidx++;
	}
	ft_strarrdel(&tav);
}

void	cln_read(t_env *e, int cs)
{
	ssize_t	r;
	char	buf[BUF_SIZE + 1];
	char	*cmd;

	r = recv(cs, buf, BUF_SIZE, 0);
	if (r <= 0)
	{
		part_all(e, cs);
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		buf[r] = '\0';
		e->fds[cs].buf_read = ft_strjoin_free_l(e->fds[cs].buf_read, buf);
		while ((cmd = get_cmd(&e->fds[cs].buf_read)) != NULL)
		{
			search_cmd(e, cmd, cs);
			ft_strdel(&cmd);
		}
	}
}

void	cln_write(t_env *e, int cs)
{
	size_t	size;
	char	*tmp;
	long	re;

	size = ((ft_strlen(e->fds[cs].buf_write) < BUF_SIZE) ?
			ft_strlen(e->fds[cs].buf_write) : BUF_SIZE);
	tmp = e->fds[cs].buf_write;
	re = XL(-1, send(cs, tmp, size, 0), "send");
	if (re > 0)
	{
		e->fds[cs].buf_write = ft_strsub(e->fds[cs].buf_write,
				(unsigned int)re, size - re);
		ft_strdel(&tmp);
	}
}
