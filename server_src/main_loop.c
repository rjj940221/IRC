//
// Created by Robert JONES on 2017/07/17.
//


#include "irc_server.h"

void	init_fd(t_env *e)
{
	int	i;

	i = 0;
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	while (i < MAX_SOCK)
	{
		if (e->fds[i].type != FD_FREE)
		{
			FD_SET(i, &e->fd_read);
			if (e->fds[i].buf_write)
			{
				FD_SET(i, &e->fd_write);
			}
			e->max = MAX(e->max, i);
		}
		i++;
	}
}

void	check_fd(t_env *e)
{
	int	i;

	i = 0;
	while ((i < MAX_SOCK) && (e->r > 0))
	{
		if (FD_ISSET(i, &e->fd_read))
			e->fds[i].fct_read(e, i);
		if (FD_ISSET(i, &e->fd_write))
			e->fds[i].fct_write(e, i);
		if (FD_ISSET(i, &e->fd_read) || FD_ISSET(i, &e->fd_write))
			e->r--;
		i++;
	}
}

void	main_loop(t_env *env)
{
	while (1)
	{
		init_fd(env);
		env->r = select(env->max + 1, &env->fd_read, &env->fd_write, NULL, NULL);
		check_fd(env);
	}
}
