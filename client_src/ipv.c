//
// Created by Robert JONES on 2017/07/17.
//


#include "irc_client.h"

int		ipv4()
{
	int				sock;
	struct protoent	*pt;

	pt = (struct protoent*)Xv(NULL, getprotobyname("tcp"), "failed to get protocol");
	sock = Xi(-1, socket(PF_INET, SOCK_STREAM, pt->p_proto),"failed to make socket");
	return (sock);
}