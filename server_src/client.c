//
// Created by Robert JONES on 2017/07/17.
//


#include "irc_server.h"

void search_cmd(t_env *env, char *cmd, int sock)
{
	char **tav;
	int cidx;
	size_t gidx;

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



void cln_read(t_env *e, int cs)
{
	ssize_t r;
	char buf[BUF_SIZE + 1];
	int i;
	char *cmd;

	r = recv(cs, buf, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	} else
	{
		buf[r] = '\0';
		e->fds[cs].buf_read = ft_strjoin_free_l(e->fds[cs].buf_read, buf);
		while ((cmd = get_cmd(&e->fds[cs].buf_read)) != NULL)
		{
			/*i = 0;
			while (i < MAX_FD)
			{
				if ((e->fds[i].type == FD_CLIENT) && (i != cs))
					e->fds[i].buf_write = ft_strjoin_free_l(e->fds[i].buf_write, cmd);
				i++;
			}*/
			search_cmd(e, cmd, cs);
			ft_strdel(&cmd);
		}
	}
}

void cln_write(t_env *e, int cs)
{
	size_t size;
	char *tmp;
	long re;

	size = ((ft_strlen(e->fds[cs].buf_write) < BUF_SIZE) ? ft_strlen(e->fds[cs].buf_write) : BUF_SIZE);
	tmp = e->fds[cs].buf_write;
	re = Xl(-1, send(cs, tmp, size, 0), "send");
	if (re > 0)
	{
		e->fds[cs].buf_write = ft_strsub(e->fds[cs].buf_write, (unsigned int)re, size - re);
		ft_strdel(&tmp);
	} /*else
	{
		e->fds[cs].buf_write =;
	}*/
}