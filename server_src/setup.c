//
// Created by Robert JONES on 2017/07/17.
//

#include <netinet/in.h>
#include <tclDecls.h>
#include "irc_server.h"

void	clean_fd(t_fd *fd)
{
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	fd->buf_write = NULL;
	fd->type = FD_FREE;
}

void	init_env(t_env *env)
{
	int					svr_sock;
	struct sockaddr_in	sin;
	size_t	i;

	env->fds =  Xv(NULL, malloc(sizeof(t_env) * MAX_FD), "socket list");
	i = 0;
	while (i < MAX_FD)
		clean_fd(&env->fds[i++]);
	svr_sock = ipv4();
	if (svr_sock >= MAX_FD)
		print_err_exit("socket list", __FILE__, __LINE__, "socket out of range");
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(/*env->port*/8080);
	Xi(-1, bind(svr_sock, (struct sockaddr*)&sin, sizeof(sin)), "bind");
	Xi(-1, listen(svr_sock, 42), "listen");
	env->fds[svr_sock].type = FD_SERV;
	env->fds[svr_sock].fct_read = svr_rcv;
}