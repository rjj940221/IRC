//
// Created by Robert JONES on 2017/07/18.
//

#include "irc_client.h"

void 				cmd_nick(char **data)
{
	char	*send_data;

	if (ft_strarrlen((const char **) data) != 2)
	{
		wprintw(g_clt_env.winrsp, "nick error: incorect paramiter count\n");
		return_cmd();
		return ;
	}
	if (check_nick(data[1]) == 0)
	{
		wprintw(g_clt_env.winrsp, "nick names must be up to 9 charicters ([a-z] | [A-Z] | '[]{})\n");
		return_cmd();
		return ;
	}
	send_data = ft_strdup("NICK ");
	send_data = ft_strjoin_free_l(send_data, data[1]);
	send_data = ft_strjoin_free_l(send_data, CMD_TERM);
	add_write_buff(send_data);
	ft_strdel(&send_data);
}