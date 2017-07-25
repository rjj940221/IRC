/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_client.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 10:04:52 by rojones           #+#    #+#             */
/*   Updated: 2017/07/14 08:22:45 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_CLIENT_H
# define FT_P_CLIENT_H

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
#include <curses.h>

#define IN_BUFF 500
# define Xv(err,res,str)	(x_void(err,res,str,__FILE__,__LINE__))
# define Xi(err,res,str)		(x_int(err,res,str,__FILE__,__LINE__))
# define Xst(err,res,str)		(x_size_t(err,res,str,__FILE__,__LINE__))
# define Xl(err,res,str)		(x_long(err,res,str,__FILE__,__LINE__))
typedef struct		s_clt_env
{
	int		svr_sock;
	char 	*host;
	char 	*port;
	char 	*writbuff;
	char 	*readbuff;
	WINDOW	*winrsp;
	WINDOW	*wincmd;
	size_t 	idx;
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
void				ft_print_exit(char *str);
void 				cmd_join(char **data);
void                cmd_leave(char **data);
void 				cmd_nick(char **data);
void 				cmd_privmsg(char **data);
void 				cmd_who(char **data);
void 				cmd_connect(char **data);
void				close_svr_sock();
void				close_ncurses();
void				close_all();
void				send_write_buff(void);
void				add_write_buff(char *data);
void				rcv_data();
void				return_cmd();
void				input_handler(int c);
long				x_long(int err, long res, char *str, char *file, int line);
int					x_int(int err, int res, char *str, char *file, int line);
size_t				x_size_t(int err, size_t res, char *str, char *file, int line);
void				*x_void(void *err, void *res, char *str, char *file, int line);
int 				ipv4(void);


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
