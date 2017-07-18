/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:20:19 by rojones           #+#    #+#             */
/*   Updated: 2017/07/13 14:20:27 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void		search_builin(char *line)
{
	char			**tav;
	t_builtin_cmd	*tmp;

	tav = ft_strsplit_fn(line, isspace);
	tmp = g_builtin_cmd;
	while (tmp->cmd)
	{
		if (strcmp(tav[0], tmp->cmd) == 0)
		{
			(*tmp->fnc)(tav);
			ft_strarrdel(&tav);
			return ;
		}
		tmp++;
	}
	printf("\x1b[mError: Command not recognised'%s'\n\x1b[0m", tav[0]);
	ft_strarrdel(&tav);
}
