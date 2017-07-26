/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:20:19 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:17:50 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	search_builin(char *line)
{
	char			**tav;
	t_builtin_cmd	*tmp;

	if (!line)
		return ;
	tav = ft_strsplit_fn(line, isspace);
	tmp = g_builtin_cmd;
	while (tmp->cmd)
	{
		if (tav && tav[0] && ft_strcmp(tav[0], tmp->cmd) == 0)
		{
			if (g_clt_env.svr_sock == -1 && ft_strcmp(tav[0], "/connect") != 0)
				wprintw(g_clt_env.winrsp, "Error: not connected\n");
			else
				(*tmp->fnc)(tav);
			ft_strarrdel(&tav);
			return (return_cmd());
		}
		tmp++;
	}
	wprintw(g_clt_env.winrsp, "Error: Command not recognised'%s'\n", tav[0]);
	return_cmd();
	ft_strarrdel(&tav);
}
