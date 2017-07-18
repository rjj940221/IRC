//
// Created by Robert JONES on 2017/07/18.
//

#include "irc_client.h"

void 				cmd_nick(char **data)
{
	char	*send_data;

	if (ft_strarrlen((const char **) data) != 2)
	{
		printf("/nick error: incorect paramiter count");
		return ;
	}
	if (check_nick(data[1]) == 0)
	{
		printf("nick names must be up to 9 charicters ([a-z] | [A-Z] | '[]{})");
		return ;
	}
	send_data = ft_strdup("NICK ");
	send_data = ft_strjoin_free_l(send_data, data[1]);
	send_data = ft_strjoin_free_l(send_data, "\r\n");
	send(g_clt_env.svr_sock, send_data, ft_strlen(send_data), 0);
	ft_strdel(&send_data);
}