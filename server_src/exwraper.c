/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exwraper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:29:41 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 07:38:09 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

size_t x_size_t(size_t err, size_t res, char *str, char *file, int line)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s, %d): %s\n",
				str, file, line, strerror(errno));
		exit(1);
	}
	return (res);
}

int x_int(int err, int res, char *str, char *file, int line)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s, %d): %s\n",
				str, file, line, strerror(errno));
		exit(1);
	}
	return (res);
}

long	x_long(int err, long res, char *str, char *file, int line)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s, %d): %s\n",
				str, file, line, strerror(errno));
		exit(1);
	}
	return (res);
}

void *x_void(void *err, void *res, char *str, char *file, int line)
{
	if (res == err)
	{
		fprintf(stderr, "%s error (%s, %d): %s\n",
				str, file, line, strerror(errno));
		exit(1);
	}
	return (res);
}

void print_err_exit(char *class, char *file, int line, char *msg)
{
	fprintf(stderr, "%s error (%s, %d): %s\n",
			class, file, line, msg);
	exit(1);
}
