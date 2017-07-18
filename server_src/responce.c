//
// Created by Robert JONES on 2017/07/18.
//

#include "irc_server.h"

void queue_rsp(t_env *env, int cs, char *rsp, char *target)
{
	char *tmp;

	tmp = ft_strjoin(rsp, " ");
	if (target)
		;
	tmp = ft_strjoin_free_l(tmp, "\r\n");
	env->fds[cs].buf_write = ft_strjoin_free(env->fds[cs].buf_write, tmp);
}