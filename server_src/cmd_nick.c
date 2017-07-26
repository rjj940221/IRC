/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 08:08:04 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:08:21 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	cmd_nick(t_env *e, char **av, int cs)
{
	size_t i;

	if (!av || !av[1])
		return (queue_rsp(e, cs, "431 :No nickname given", NULL));
	if (check_nick(av[1]))
	{
		i = 0;
		while (i < MAX_SOCK)
		{
			if (ft_strcmp(e->fds[i].nick, av[1]) == 0)
				return (queue_rsp(e, cs, "436 :Nickname collision", NULL));
			i++;
		}
		ft_strncpy(e->fds[cs].nick, av[1], ft_strlen(av[1]));
	}
	else
		return (queue_rsp(e, cs, "432 :Erroneus nickname", NULL));
}
