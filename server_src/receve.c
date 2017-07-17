#include <netinet/in.h>
#include <arpa/inet.h>
#include "irc_server.h"

void svr_rcv(t_env *env, int ss)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;

	csin_len = sizeof(csin);
	cs = Xi(-1, accept(ss, (struct sockaddr*)&csin, &csin_len), "accept");
	if (cs >= MAX_FD)
		print_err_exit("accept", __FILE__, __LINE__, "exceeds max num socket");
	printf("New client #%d from %s:%d\n", cs,
		   inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	clean_fd(&env->fds[cs]);
	env->fds[cs].type = FD_CLIENT;
	env->fds[cs].fct_read = cln_read;
	env->fds[cs].fct_write = cln_write;
}

