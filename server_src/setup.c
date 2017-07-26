/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 08:08:31 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 09:56:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include "irc_server.h"

void	clean_fd(t_fd *fd)
{
	size_t i;

	fd->fct_read = NULL;
	fd->fct_write = NULL;
	fd->buf_write = NULL;
	ft_bzero(fd->nick, 10);
	fd->type = FD_FREE;
	i = 0;
	while (i < MAX_CHANNEL)
		fd->channels[i++] = -1;
}

void	clean_channle(t_chl *chl)
{
	size_t	i;

	i = 0;
	while (i < MAX_CHANNEL_USER)
		chl->user[i++] = -1;
	ft_bzero((void *)chl->name, CHANNEL_NAME);
}

void	init_env(t_env *env)
{
	int					svr_sock;
	struct sockaddr_in	sin;
	size_t				i;

	env->fds = XV(NULL, malloc(sizeof(t_env) * MAX_SOCK), "socket list");
	i = 0;
	while (i < MAX_SOCK)
		clean_fd(&env->fds[i++]);
	i = 0;
	while (i < MAX_CHANNEL)
		clean_channle(&env->channels[i++]);
	svr_sock = ipv4();
	if (svr_sock >= MAX_SOCK)
		print_err_exit("socket list", __FILE__, __LINE__,
				"socket out of range");
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(env->port);
	XI(-1, bind(svr_sock, (struct sockaddr*)&sin, sizeof(sin)), "bind");
	XI(-1, listen(svr_sock, 42), "listen");
	env->fds[svr_sock].type = FD_SERV;
	env->fds[svr_sock].fct_read = svr_rcv;
}
