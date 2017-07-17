//
// Created by Robert JONES on 2017/07/17.
//

#ifndef IRC_IRC_H
#define IRC_IRC_H

# include <stdio.h>
# include <memory.h>
# include <sys/errno.h>
# include <stdlib.h>

# define Xv(err,res,str)	(x_void(err,res,str,__FILE__,__LINE__))
# define Xi(err,res,str)		(x_int(err,res,str,__FILE__,__LINE__))
# define Xst(err,res,str)		(x_size_t(err,res,str,__FILE__,__LINE__))
# define Xl(err,res,str)		(x_size_t(err,res,str,__FILE__,__LINE__))

long	x_long(int err, long res, char *str, char *file, int line);
int		x_int(int err, int res, char *str, char *file, int line);
size_t	x_size_t(int err, size_t res, char *str, char *file, int line);
void	*x_void(void *err, void *res, char *str, char *file, int line);
int 	ipv4(void);

#endif //IRC_IRC_H
