//
// Created by rojones on 2017/07/17.
//

#include "irc_server.h"

void 	cmd_nick(t_env *e, char **av, int cs)
{
	size_t i;

	if (!av || !av[1])
		return (queue_rsp(e, cs, "431", NULL));
	if (check_nick(av[1]))
	{
		i = 0;
		while (i < MAX_SOCK)
		{
			if (ft_strcmp(e->fds[i].nick, av[1]) == 0)
				return (queue_rsp(e, cs, "436", NULL));
			i++;
		}
		ft_strncpy(e->fds[cs].nick, av[1], ft_strlen(av[1]));
	}
	else
		return (queue_rsp(e, cs, "432", NULL));
}