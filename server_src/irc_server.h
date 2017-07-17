//
// Created by Robert JONES on 2017/07/17.
//

#ifndef IRC_IRC_SERVER_H
#define IRC_IRC_SERVER_H

#include <sys/socket.h>
# include <ctype.h>
# include <sys/select.h>
# include "../irc.h"
# include "../libft/libft.h"
# define FD_FREE	0
# define FD_SERV	1
# define FD_NSERV	2
# define FD_CLIENT	3
# define MAX_SOCK	100
# define MAX_CHANNEL	20
# define MAX_CHANNEL_USER 40
# define BUF_SIZE	4096


# define MAX(a,b)	((a > b) ? a : b)
# define USAGE		"Usage: %s <port>\n"

struct	s_env;

typedef struct	s_fd
{
	int		type;
	void	(*fct_read)(struct s_env *env, int i);
	void	(*fct_write)(struct s_env *env, int i);
	char	*buf_read;
	char	*buf_write;
	char 	nick[10];
}				t_fd;

typedef struct	s_env
{
	t_fd		*fds;
	int		port;
	int		max;
	int		r;
	fd_set	fd_read;
	fd_set	fd_write;
}		t_env;

typedef struct	s_cmd
{
	char *name;
	void (*fnc)();
}				t_cmd;

void	init_env(t_env *e);
void	get_opt(t_env *e, int ac, char **av);
void	main_loop(t_env *env);
void	svr_rcv(t_env *e, int ss);
void	cln_read(t_env *e, int cs);
void	cln_write(t_env *e, int cs);
void	clean_fd(t_fd *fd);
void	init_fd(t_env *e);
void	check_fd(t_env *e);
void	print_err_exit(char *class, char *file, int line, char *msg);
void 	cmd_nick(t_env *e, char **av, int cs);

const static t_cmd g_cmds[] = {
		{"NICK", cmd_nick},
		{NULL, NULL}
};

#endif //IRC_IRC_SERVER_H
