/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_privmsg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:52:44 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:53:13 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	cmd_privmsg(char **data)
{
	char	*send_data;
	size_t	ac;

	ac = ft_strarrlen((const char **)data);
	if (ac > 2)
	{
		send_data = ft_strjoin("PRIVMSG ", data[1]);
		send_data = ft_strjoin_free_l(send_data, " :");
		ac = 1;
		while (data[++ac])
		{
			send_data = ft_strjoin_free_l(send_data, data[ac]);
			send_data = ft_strjoin_free_l(send_data, " ");
		}
		send_data = ft_strjoin_free_l(send_data, CMD_TERM);
		add_write_buff(send_data);
	}
	else
	{
		wprintw(g_clt_env.winrsp, "usage: /msg <nick> <message>"
				"\n\te.g.\t/msg bob,#bar hi bob and all on #foo\n");
		return_cmd();
	}
}
