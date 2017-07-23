//
// Created by Robert JONES on 2017/07/20.
//

#include "irc_server.h"

char *forward_msg(char *sender, char *recv, char *msg)
{
	char *forward;

	forward = ft_strjoin(":", sender);
	forward = ft_strjoin_free_l(forward, " PRIVMSG ");
	forward = ft_strjoin_free_l(forward, recv);
	forward = ft_strjoin_free_l(forward, " ");
	forward = ft_strjoin_free_l(forward, msg);
	return (forward);
}

void privmsg_chl(t_env *e, char *chl_name, char *msg, int cs)
{
	int i;
	t_chl *chl;
	char *forward;

	chl = find_channel(e, chl_name, &i);
	if (chl == NULL)
		return (queue_rsp(e, cs, "401 :No such nick/channel", NULL));
	if (user_in_chl(chl, cs) == FALSE)
		return (queue_rsp(e, cs, "404 :Cannot send to channel", NULL));
	i = 0;
	while (i < MAX_CHANNEL_USER && chl->user[i] != -1)
	{
		if (chl->user[i] != cs)
		{
			forward = forward_msg(e->fds[cs].nick, e->fds[chl->user[i]].nick, msg);
			queue_rsp(e, chl->user[i], forward, NULL);
			ft_strdel(&forward);
		}
		i++;
	}
}

void privmsg_nick(t_env *e, char *nick, char *msg, int cs)
{
	size_t i;
	char *forward;

	i = 0;
	while (i < MAX_SOCK)
	{
		if (ft_strcmp(nick, e->fds[i].nick) == 0)
		{
			forward = forward_msg(e->fds[cs].nick, nick, msg);
			queue_rsp(e, (int)i, forward, NULL);
			ft_strdel(&forward);
			return ;
		}
		i++;
	}
	queue_rsp(e, cs, "401 :No such nick/channel", NULL);
}

t_bool check_privmsg(t_env *e, char **av, int cs)
{
	if (av[1] == NULL || av[1][0] == ':')
	{
		queue_rsp(e, cs, "411 :No recipient given", NULL);
		return (FALSE);
	}
	if (av[1] == NULL || av[2] == NULL || av[2][0] != ':')
	{
		queue_rsp(e, cs, "412 :No text to send", NULL);
		return (FALSE);
	}
	return (TRUE);
}

void cmd_privmsg(t_env *e, char **av, int cs)
{
	char **spl;
	char **tmp;

	if (check_privmsg(e, av, cs) == TRUE)
	{
		spl = ft_strsplit(av[1], ',');
		tmp = spl;
		while (*tmp)
		{
			if (check_channle(*tmp) == TRUE)
				privmsg_chl(e, *tmp, av[2], cs);
			else
				privmsg_nick(e, *tmp, av[2], cs);
			tmp++;
		}
		ft_strarrdel(&spl);
	}
}