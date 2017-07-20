//
// Created by Robert JONES on 2017/07/20.
//


#include "irc_client.h"

void	cmd_leave(char **data)
{
    char	*send_data;
    size_t ac;

    ac = ft_strarrlen((const char **)data);
    if (ac < 3)
    {
        send_data = ft_strjoin("PART ", data[1]);
        send_data = ft_strjoin_free_l(send_data, CMD_TERM);
        add_write_buff(send_data);
    }
    else
        printf("usage: /leave [#channel[,#channel]] \n\te.g.\t/leave #foo,#bar");
}