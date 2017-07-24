//
// Created by Robert JONES on 2017/07/20.
//

#include "irc_client.h"

void	cmd_join(char **data)
{
	char	*send_data;
	size_t ac;

	ac = ft_strarrlen((const char **)data);
	if (ac == 2)
	{
		send_data = ft_strjoin("JOIN ", data[1]);
		send_data = ft_strjoin_free_l(send_data, CMD_TERM);
		add_write_buff(send_data);
	}
	else
		printf("usage: /join <#channel>[,#channel] \n\te.g.\t/join #foo,#bar\n");
}