/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_client.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:28:40 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:29:03 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_CLIENT_H
# define IRC_CLIENT_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/ioctl.h>
# include <net/if.h>
# include <netinet/in.h>
# include <printf.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <netdb.h>
# include <memory.h>
# include <zconf.h>
# include <libft.h>
# include <sys/mman.h>
# include <arpa/inet.h>
# include "../irc.h"
# include "../libft/libft.h"
# include <ctype.h>
# include <fcntl.h>
# include <printf.h>
# include <stdio.h>
# include <sys/param.h>
# include <sys/errno.h>
# include <curses.h>

# define IN_BUFF 500
# define XV(err,res,str)	(x_void(err,res,str))
# define XI(err,res,str)	(x_int(err,res,str))
# define XST(err,res,str)	(x_size_t(err,res,str))
# define XL(err,res,str)	(x_long(err,res,str))

typedef struct		s_clt_env
{
	int		svr_sock;
	char	*host;
	char	*port;
	char	*writbuff;
	char	*readbuff;
	WINDOW	*winrsp;
	WINDOW	*wincmd;
	size_t	idx;
}					t_clt_env;

typedef void(*t_builtin)(char **data);

typedef struct		s_builtin_cmd
{
	char		*cmd;
	t_builtin	fnc;
}					t_builtin_cmd;

extern t_clt_env	g_clt_env;

void				connect_to_server(void);
void				search_builin(char *line);
int					check_port(const char *str);
void				cmd_join(char **data);
void				cmd_leave(char **data);
void				cmd_nick(char **data);
void				cmd_privmsg(char **data);
void				cmd_who(char **data);
void				cmd_connect(char **data);
void				close_svr_sock();
void				close_ncurses();
void				close_all();
void				send_write_buff(void);
void				add_write_buff(char *data);
void				rcv_data();
void				return_cmd();
void				input_handler(int c);
long				x_long(int err, long res, char *str);
int					x_int(int err, int res, char *str);
size_t				x_size_t(size_t err, size_t res, char *str);
void				*x_void(void *err, void *res, char *str);
int					ipv4(void);
void				print_err_exit(char *class, char *file, int line,
									char *msg);
void				initwindow();

static t_builtin_cmd	g_builtin_cmd[] = {
	{"/connect", cmd_connect},
	{"/join", cmd_join},
	{"/leave", cmd_leave},
	{"/nick", cmd_nick},
	{"/msg", cmd_privmsg},
	{"/who", cmd_who},
	{NULL, NULL}
};

#endif
