/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_leave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:30:12 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:31:32 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	cmd_leave(char **data)
{
	char	*send_data;
	size_t	ac;

	ac = ft_strarrlen((const char **)data);
	if (ac < 3)
	{
		send_data = ft_strjoin("PART ", data[1]);
		send_data = ft_strjoin_free_l(send_data, CMD_TERM);
		add_write_buff(send_data);
	}
	else
	{
		wprintw(g_clt_env.winrsp, "usage: /leave [#channel"
				"[,#channel]] \n\te.g.\t/leave #foo,#bar");
		return_cmd();
	}
}
