/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_server.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:39:06 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 08:47:34 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_IRC_SERVER_H
# define IRC_IRC_SERVER_H

# include <sys/socket.h>
# include <ctype.h>
# include <sys/select.h>
# include "../irc.h"
# include "../libft/libft.h"

# define XV(err,res,str)	(x_void(err,res,str))
# define XI(err,res,str)	(x_int(err,res,str))
# define XST(err,res,str)	(x_size_t(err,res,str))
# define XL(err,res,str)	(x_long(err,res,str))
# define FD_FREE	0
# define FD_SERV	1
# define FD_NSERV	2
# define FD_CLIENT	3
# define MAX_SOCK	100
# define MAX_CHANNEL	20
# define MAX_CHANNEL_USER 40
# define MAX(a,b)	((a > b) ? a : b)
# define USAGE		"Usage: %s <port>\n"

struct s_env;

typedef struct	s_fd
{
	int		type;
	void	(*fct_read)(struct s_env *env, int i);
	void	(*fct_write)(struct s_env *env, int i);
	char	*buf_read;
	char	*buf_write;
	char	nick[10];
	int		channels[MAX_CHANNEL];
}				t_fd;

typedef struct	s_channel
{
	char	name[CHANNEL_NAME];
	int		user[MAX_CHANNEL_USER];
}				t_chl;

typedef struct	s_env
{
	t_fd	*fds;
	int		port;
	int		max;
	int		r;
	fd_set	fd_read;
	fd_set	fd_write;
	t_chl	channels[MAX_CHANNEL];
}				t_env;

typedef struct	s_cmd
{
	char	*name;
	void	(*fnc)(t_env *env, char **av, int sock);
}				t_cmd;

void			cln_read(t_env *e, int cs);
void			cln_write(t_env *e, int cs);
void			clean_channle(t_chl *chl);
void			clean_fd(t_fd *fd);
t_chl			*find_channel(t_env *e, char *name, int *chlidx);
void			get_opt(t_env *e, int ac, char **av);
void			init_env(t_env *e);
void			main_loop(t_env *env);
char			*rpl_namrply(t_chl *chl, t_env *e);
void			svr_rcv(t_env *e, int ss);
void			init_fd(t_env *e);
void			check_fd(t_env *e);
void			print_err_exit(char *class, char *file, int line, char *msg);
void			cmd_join(t_env *e, char **av, int cs);
void			cmd_names(t_env *e, char **av, int cs);
void			cmd_nick(t_env *e, char **av, int cs);
void			cmd_part(t_env *e, char **av, int cs);
void			cmd_privmsg(t_env *e, char **av, int cs);
void			queue_rsp(t_env *env, int cs, char *rsp, char *target);
t_bool			user_in_chl(t_chl *chl, int user_id);
void			part_all(t_env *e, int cs);
long			x_long(int err, long res, char *str);
int				x_int(int err, int res, char *str);
size_t			x_size_t(size_t err, size_t res, char *str);
void			*x_void(void *err, void *res, char *str);
int				ipv4(void);

const static t_cmd	g_cmds[] = {
	{"JOIN", cmd_join},
	{"NAMES", cmd_names},
	{"NICK", cmd_nick},
	{"PART", cmd_part},
	{"PRIVMSG", cmd_privmsg},
	{NULL, NULL}
};

#endif
