//
// Created by rojones on 2017/07/17.
//

#include "irc_server.h"

void 	cmd_nick(t_env *e, char **av, int cs)
{
	ft_strncpy(e->fds[cs].nick, av[1], (ft_strlen(av[1]) < 10) ? ft_strlen(av[1]) : 9);
}