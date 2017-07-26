/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:23:41 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:23:50 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	cmd_connect(char **data)
{
	size_t	ac;

	ac = ft_strarrlen((const char **)data);
	if (ac > 3 || ac < 2 || (ac == 3 && check_port(data[2]) == -1))
	{
		wprintw(g_clt_env.winrsp,
				"Incorect paramiter expecting '/connect <host> [port]'\n");
		return_cmd();
	}
	else
	{
		close(g_clt_env.svr_sock);
		g_clt_env.host = data[1];
		if (ac == 3)
			g_clt_env.port = data[2];
		else
			g_clt_env.port = NULL;
		connect_to_server();
	}
}
