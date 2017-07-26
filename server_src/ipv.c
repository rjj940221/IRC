/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 08:14:50 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:47:53 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

int		ipv4(void)
{
	int				sock;
	struct protoent	*pt;

	pt = (struct protoent*)XV(NULL, getprotobyname("tcp"),
			"failed to get protocol");
	sock = XI(-1, socket(PF_INET, SOCK_STREAM, pt->p_proto),
			"failed to make socket");
	return (sock);
}
