//
// Created by Robert JONES on 2017/07/17.
//


#include "../irc.h"

size_t x_size_t(int err, size_t res, char *str, char *file, int line)
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