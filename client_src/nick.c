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
	}
	send_data = ft_strdup("NICK ");

}