//
// Created by rojones on 2017/07/18.
//

#include "irc_server.h"

t_bool	part_channel(t_env *e, int cs, t_chl *chl)
{
	size_t ui;
	t_bool found;

	ui = 0;
	found = FALSE;
	while (ui < MAX_CHANNEL_USER - found)
	{
		if (found)
			chl->user[ui] = chl->user[ui + 1];
		else if (chl->user[ui] == cs)
		{
			if (ui < MAX_CHANNEL_USER - 1)
				chl->user[ui] = chl->user[ui + 1];
			else
				chl->user[ui] = -1;
			found = TRUE;
		}
		ui++;
	}
	if (found == TRUE)
		chl->user[MAX_CHANNEL_USER - 1] = -1;
	if (chl->user[0] == 0)
		clean_channle(chl);
	return (found);
}

void part_all(t_env *e, int cs)
{
	size_t ci;

	ci = 0;
	while (ci < MAX_CHANNEL && e->fds[cs].channels[ci] != -1)
	{
		part_channel(e, cs, &e->channels[e->fds[cs].channels[ci]]);
		e->fds[cs].channels[ci] = -1;
		ci++;
	}
}

void remove_channel_idx(t_fd *fd, int chlidx)
{
	size_t	i;
	t_bool	found;

	i = 0;
	found = FALSE;
	while (i < MAX_CHANNEL - found && fd->channels[i] != -1)
	{
		if (fd->channels[i] == chlidx)
		{
			if (i != MAX_CHANNEL - 1)
				fd->channels[i] = fd->channels[i + 1];
			else
				fd->channels[i] = -1;
			found = TRUE;
		}
		i++;
	}
}

void part_list(t_env *e, char **spl, int cs)
{
	size_t ci;

	while (spl && *spl)
	{
		ci = 0;
		while (ci < MAX_CHANNEL)
		{
			if (ft_strcmp(e->channels[ci].name, *spl) == 0)
				if (!part_channel(e, cs, &e->channels[ci]))
					queue_rsp(e, cs, "442", NULL);
			ci++;
		}
		if (ci == MAX_CHANNEL)
			queue_rsp(e, cs,"403", NULL);
		spl++;
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
	else
		queue_rsp(e, cs, "461", NULL);
}