/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:15:23 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:16:09 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	cmd_join(char **data)
{
	char	*send_data;
	size_t	ac;

	ac = ft_strarrlen((const char **)data);
	if (ac == 2)
	{
		send_data = ft_strjoin("JOIN ", data[1]);
		send_data = ft_strjoin_free_l(send_data, CMD_TERM);
		add_write_buff(send_data);
	}
	else
	{
		wprintw(g_clt_env.winrsp, "usage: /join <#channel>[,#channel] "
				"\n\te.g.\t/join #foo,#bar\n");
		return_cmd();
	}
}
