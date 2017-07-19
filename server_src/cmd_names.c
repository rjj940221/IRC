//
// Created by rojones on 2017/07/19.
//

#include "irc_server.h"

void 	cmd_names(t_env *e, char **av, int cs)
{
	size_t ac;

	ac = ft_strarrlen(av);
	if (ac > 2)
		return (queue_rsp(e, cs, "366", NULL));
}