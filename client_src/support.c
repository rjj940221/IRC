/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:19:55 by rojones           #+#    #+#             */
/*   Updated: 2017/07/13 13:12:33 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

int		check_port(const char *str)
{
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (-1);
		str++;
	}
	return (1);
}

void	close_svr_sock()
{
	close(g_clt_env.svr_sock);
	g_clt_env.svr_sock = -1;
}

void	ft_print_exit(char *str)
{
	printf("\x1b[31mERROR: %s\x1b[31m\n", str);
	if (g_clt_env.svr_sock > -1)
		close(g_clt_env.svr_sock);
	exit(1);
}
