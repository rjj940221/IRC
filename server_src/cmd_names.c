/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 08:22:30 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:33:58 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	name_all(t_env *e, int cs)
{
	size_t	i;
	char	*nrsp;
	char	*rsp;

	i = 0;
	while (i < MAX_CHANNEL)
	{
		if (e->channels[i].name[0] != '\0')
		{
			if ((nrsp = rpl_namrply(&e->channels[i], e)))
			{
				queue_rsp(e, cs, nrsp, NULL);
				ft_strdel(&nrsp);
			}
			rsp = ft_strjoin("366 ", e->channels[i].name);
			rsp = ft_strjoin_free_l(rsp, " :End of NAMES list");
			queue_rsp(e, cs, rsp, NULL);
			ft_strdel(&rsp);
		}
		i++;
	}
}

void	name_list(t_env *e, char **av, int cs)
{
	char	**spl;
	char	**tmp;
	char	*names;
	char	*rsp;
	int		chidx;

	spl = ft_strsplit(av[1], ',');
	tmp = spl;
	while (tmp && *tmp)
	{
		if ((names = rpl_namrply(find_channel(e, *tmp, &chidx), e)))
		{
			queue_rsp(e, cs, names, NULL);
			ft_strdel(&names);
		}
		rsp = ft_strjoin("366 ", *tmp);
		rsp = ft_strjoin_free_l(rsp, " :End of NAMES list");
		queue_rsp(e, cs, rsp, NULL);
		ft_strdel(&rsp);
		tmp++;
	}
	ft_strarrdel(&spl);
}

void	cmd_names(t_env *e, char **av, int cs)
{
	size_t	ac;

	ac = ft_strarrlen((const char **)av);
	if (ac > 2)
		return (queue_rsp(e, cs, "366 :End of NAMES list", NULL));
	else if (ac == 1)
		return (name_all(e, cs));
	else
		return (name_list(e, av, cs));
}
