/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:29:28 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:32:00 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

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
