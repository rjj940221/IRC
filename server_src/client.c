//
// Created by Robert JONES on 2017/07/17.
//


#include "irc_server.h"

void cln_read(t_env *e, int cs)
{
	ssize_t r;
	int i;

	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	} else
	{
		e->fds[cs].buf_read[r] = '\0';
		i = 0;
		while (i < MAX_FD)
		{
			if ((e->fds[i].type == FD_CLIENT) && (i != cs))
				e->fds[i].buf_write = ft_strjoin_free_l(e->fds[i].buf_write,
						(const char *)e->fds[cs].buf_read);
			i++;
		}
	}
}

void cln_write(t_env *e, int cs)
{
	size_t	size;
	char 	*tmp;
	long	re;

	size = ((ft_strlen(e->fds[cs].buf_write) < BUF_SIZE) ? ft_strlen(e->fds[cs].buf_write) : BUF_SIZE);
	tmp = e->fds[cs].buf_write;
	re = Xl(-1, send(cs, tmp, size, 0), "send");
	if (re > 0)
	{
		e->fds[cs].buf_write = ft_strsub(e->fds[cs].buf_write, 0, (size_t)re);
		ft_strdel(&tmp);
	}
}