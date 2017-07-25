//
// Created by Robert JONES on 2017/07/20.
//

#include "irc_client.h"

void cmd_who(char **data)
{
	char *send_data;
	size_t ac;

	ac = ft_strarrlen((const char **) data);
	if (ac < 3)
	{
		send_data = ft_strjoin("NAMES ", data[1]);
		send_data = ft_strjoin_free_l(send_data, CMD_TERM);
		add_write_buff(send_data);
	}
	else
	{
		wprintw(g_clt_env.winrsp, "usage: /who [#channel[,#channel]] \n\te.g.\t/who #foo,#bar");
		return_cmd();
	}
}