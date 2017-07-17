//
// Created by Robert JONES on 2017/07/17.
//


#include "irc_server.h"

int		check_port(const char *str)
{
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (-1);
		str++;
	}
	return (1);
}

void	get_opt(t_env *env, int ac, char **av)
{
	if (ac != 2 || check_port(av[1]) == -1)
	{
		printf(USAGE, av[0]);
		exit(1);
	}
	env->port = ft_atoi(av[1]);
}

int main(int ac, char **av)
{
	t_env	env;

	get_opt(&env, ac, av);
	init_env(&env);
	main_loop(&env);
}