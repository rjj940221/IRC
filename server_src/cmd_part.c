//
// Created by rojones on 2017/07/18.
//

#include "irc_server.h"

void part_all(t_env *e, int cs)
{
	size_t ci;
	size_t ui;
	t_bool found;

	ci = 0;
	while (ci < MAX_CHANNEL)
	{
		if (e->channels[ci].name[0] != '\0')
		{
			ui = 0;
			found = FALSE;
			while (ui < MAX_CHANNEL_USER - found)
			{
				if (found)
					e->channels[ci].user[ui] = e->channels[ci].user[ui + 1];
				else if (e->channels[ci].user[ui] == cs)
				{
					if (ui < MAX_CHANNEL_USER - 1)
						e->channels[ci].user[ui] = e->channels[ci].user[ui + 1];
					else
						e->channels[ci].user[ui] = -1;
					found = TRUE;
				}
				ui++;
			}
		}
		ci++;
	}
}

void cmd_part(t_env *e, char **av, int cs)
{
	size_t ac;
	char **spl;

	ac = ft_strarrlen((const char **) av);
	if (ac == 1)
		part_all(e, cs);
	else if (ac == 2)
	{
		spl = ft_strsplit(av[1], ',');
		part_list(e, spl, cs);
		ft_strarrdel(&spl);
	}
	queue_rsp(e, cs, "461", NULL);
}