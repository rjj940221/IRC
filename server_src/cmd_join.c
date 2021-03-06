/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 08:17:59 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:31:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	save_channle(t_env *e, int chlidx, int cs)
{
	size_t	i;

	i = 0;
	while (i < MAX_CHANNEL)
	{
		if (e->fds[cs].channels[i] == -1)
		{
			e->fds[cs].channels[i] = chlidx;
			return ;
		}
		i++;
	}
}

void	join_channel(t_env *e, t_chl *chl, int cs, int chlidx)
{
	size_t	i;
	char	*nrpl;

	i = 0;
	while (i < MAX_CHANNEL)
		if (e->fds[cs].channels[i++] == chlidx)
			return ;
	i = 0;
	while (i < MAX_CHANNEL_USER)
	{
		if (chl->user[i] == -1)
		{
			chl->user[i] = cs;
			save_channle(e, chlidx, cs);
			if ((nrpl = rpl_namrply(chl, e)))
			{
				queue_rsp(e, cs, nrpl, NULL);
				ft_strdel(&nrpl);
			}
			return ;
		}
		i++;
	}
	if (i == MAX_CHANNEL_USER)
		queue_rsp(e, cs, "471", NULL);
}

void	create_channel(t_env *e, char *name, int cs)
{
	size_t	i;
	char	*nrpl;

	i = 0;
	while (i < MAX_CHANNEL)
	{
		if (e->channels[i].name[0] == '\0')
		{
			e->channels[i].user[0] = cs;
			ft_strcpy(e->channels[i].name, name);
			save_channle(e, (int)i, cs);
			if ((nrpl = rpl_namrply(&e->channels[i], e)))
			{
				queue_rsp(e, cs, nrpl, NULL);
				ft_strdel(&nrpl);
			}
			return ;
		}
		i++;
	}
	if (i == MAX_CHANNEL)
		queue_rsp(e, cs, "405", NULL);
}

void	cmd_join(t_env *e, char **av, int cs)
{
	size_t	ac;
	char	**spl;
	char	**tas;
	t_chl	*chl;
	int		idx;

	if (e->fds[cs].nick[0] == '\0')
		return (queue_rsp(e, cs, "476 :Nick not set", NULL));
	ac = ft_strarrlen((const char **)av);
	if (ac < 2 || ac > 3)
		return (queue_rsp(e, cs, "461", NULL));
	spl = ft_strsplit(av[1], ',');
	tas = spl;
	while (*tas)
	{
		if (check_channle(*tas) == FALSE)
			return (queue_rsp(e, cs, "476 :invalid channel name", NULL));
		chl = find_channel(e, *tas, &idx);
		if (chl)
			join_channel(e, chl, cs, idx);
		else
			create_channel(e, *tas, cs);
		tas++;
	}
	ft_strarrdel(&spl);
}
