/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_namrply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 08:40:25 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:41:36 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

char	*rpl_namrply(t_chl *chl, t_env *e)
{
	size_t	idx;
	char	*names;
	char	*rsp;

	idx = 0;
	names = NULL;
	rsp = NULL;
	if (!chl)
		return (NULL);
	while (idx < MAX_CHANNEL_USER && chl->user[idx] != -1)
	{
		if (names)
			names = ft_strjoin_free_l(names, " ");
		names = ft_strjoin_free_l(names, e->fds[chl->user[idx]].nick);
		idx++;
	}
	if (names)
	{
		rsp = ft_strjoin("353 ", chl->name);
		rsp = ft_strjoin_free_l(rsp, " :");
		rsp = ft_strjoin_free(rsp, names);
	}
	return (rsp);
}
