/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 08:23:22 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:24:27 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	queue_rsp(t_env *env, int cs, char *rsp, char *target)
{
	char *tmp;

	tmp = ft_strjoin(rsp, " ");
	if (target)
		;
	tmp = ft_strjoin_free_l(tmp, CMD_TERM);
	env->fds[cs].buf_write = ft_strjoin_free(env->fds[cs].buf_write, tmp);
}
