//
// Created by Robert JONES on 2017/07/17.
//

#ifndef IRC_IRC_H
#define IRC_IRC_H

# include <netdb.h>
# include <stdio.h>
# include <memory.h>
# include <sys/errno.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUF_SIZE	4096
# define CHANNEL_NAME 200
# define Xv(err,res,str)	(x_void(err,res,str,__FILE__,__LINE__))
# define Xi(err,res,str)		(x_int(err,res,str,__FILE__,__LINE__))
# define Xst(err,res,str)		(x_size_t(err,res,str,__FILE__,__LINE__))
# define Xl(err,res,str)		(x_long(err,res,str,__FILE__,__LINE__))
# define FALSE	0
# define TRUE	1
# define CMD_TERM "\r\n"

typedef char t_bool;

long	x_long(int err, long res, char *str, char *file, int line);
int		x_int(int err, int res, char *str, char *file, int line);
size_t	x_size_t(int err, size_t res, char *str, char *file, int line);
void	*x_void(void *err, void *res, char *str, char *file, int line);
int 	ipv4(void);
int		check_nick(char *nick);
t_bool	check_channle(char *name);
char 	**split_cmd(char *cmd);
char    *get_cmd(char **read_buff);

#endif //IRC_IRC_H
