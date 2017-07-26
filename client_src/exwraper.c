/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exwraper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:34:57 by rojones           #+#    #+#             */
/*   Updated: 2017/07/26 07:40:25 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

size_t	x_size_t(size_t err, size_t res, char *str)
{
	if (res == err)
	{
		close_all();
		fprintf(stderr, "%s error: %s\n",
				str, strerror(errno));
		exit(1);
	}
	return (res);
}

int		x_int(int err, int res, char *str)
{
	if (res == err)
	{
		close_all();
		fprintf(stderr, "%s error: %s\n",
				str, strerror(errno));
		exit(1);
	}
	return (res);
}

long	x_long(int err, long res, char *str)
{
	if (res == err)
	{
		close_all();
		fprintf(stderr, "%s error: %s\n",
				str, strerror(errno));
		exit(1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str)
{
	if (res == err)
	{
		close_all();
		fprintf(stderr, "%s error: %s\n",
				str, strerror(errno));
		exit(1);
	}
	return (res);
}

void	print_err_exit(char *class, char *file, int line, char *msg)
{
	close_all();
	fprintf(stderr, "%s error (%s, %d): %s\n",
			class, file, line, msg);
	exit(1);
}
