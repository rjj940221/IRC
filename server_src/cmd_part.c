/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:26:54 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:22:17 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

t_bool	part_channel(int cs, t_chl *chl)
{
	int		ui;
	t_bool	found;

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
	if (chl->user[0] == -1)
		clean_channle(chl);
	return (found);
}

void	part_all(t_env *e, int cs)
{
	int	ci;

	ci = 0;
	while (ci < MAX_CHANNEL && e->fds[cs].channels[ci] != -1)
	{
		part_channel(cs, &e->channels[e->fds[cs].channels[ci]]);
		e->fds[cs].channels[ci] = -1;
		ci++;
	}
}

void	remove_channel_idx(t_fd *fd, int chlidx)
{
	int		i;
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

void	part_list(t_env *e, char **spl, int cs)
{
	size_t	ci;

	while (spl && *spl)
	{
		ci = 0;
		while (ci < MAX_CHANNEL)
		{
			if (ft_strcmp(e->channels[ci].name, *spl) == 0)
			{
				if (part_channel(cs, &e->channels[ci]) == FALSE)
					queue_rsp(e, cs, "442 :You're not on that channel", NULL);
				else
					remove_channel_idx(&e->fds[cs], ci);
				break ;
			}
			ci++;
		}
		if (ci == MAX_CHANNEL)
			queue_rsp(e, cs, "403 :No such channel", NULL);
		spl++;
	}
}

void	cmd_part(t_env *e, char **av, int cs)
{
	size_t	ac;
	char	**spl;

	ac = ft_strarrlen((const char **)av);
	if (ac == 1)
		part_all(e, cs);
	else if (ac == 2)
	{
		spl = ft_strsplit(av[1], ',');
		part_list(e, spl, cs);
		ft_strarrdel(&spl);
	}
	else
		queue_rsp(e, cs, "461 :Not enough parameters", NULL);
}
