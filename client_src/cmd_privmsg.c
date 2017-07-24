//
// Created by Robert JONES on 2017/07/20.
//

#include "irc_client.h"

void	cmd_privmsg(char **data)
{
	char	*send_data;
	size_t ac;

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
		printf("usage: /msg <nick> <message>\n\te.g.\t/msg bob,#bar hi bob and all on #foo\n");
}