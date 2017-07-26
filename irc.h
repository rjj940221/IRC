/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:38:25 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 10:54:17 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_IRC_H
# define IRC_IRC_H

# include <netdb.h>
# include <stdio.h>
# include <memory.h>
# include <sys/errno.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUF_SIZE	4096
# define CHANNEL_NAME 200
# define FALSE	0
# define TRUE	1
# define CMD_TERM "\r\n"

typedef char	t_bool;

int		check_nick(char *nick);
t_bool	check_channle(char *name);
char	**split_cmd(char *cmd);
char	*get_cmd(char **read_buff);

#endif
