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

typedef struct		s_clt_env
{
	int		svr_sock;
	char 	*host;
	char 	*port;
}					t_clt_env;

typedef void(*t_builtin)(char **argv);

typedef struct		s_builtin_cmd
{
	char		*cmd;
	t_builtin	fnc;
}					t_builtin_cmd;

extern t_clt_env	g_clt_env;

void				connect_to_server(void);
void				search_builin(char *line);
int					check_port(const char *str);
void				ft_cd(char **argv);
//void				ft_cmd_responce_dell(t_cmd_rsp **rsp);
void				ft_print_exit(char *str);
//t_cmd_rsp			*ft_get_cmd_responce(void);
//void				ft_process_rsp(t_cmd_rsp rsp);
//void				ft_send_cmd(t_cmd cmd);
size_t				ft_receve_data(char **data);
void				ft_data_connection();

static t_builtin_cmd	g_builtin_cmd[] = {
	{NULL, NULL}
};

#endif
