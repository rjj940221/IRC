//
// Created by rojones on 2017/07/18.
//

#include "irc_server.h"

void	join_channel(t_env *e, t_chl *chl, int cs)
{
	size_t i;

	i = 0;
	while (i < MAX_CHANNEL_USER)
	{
		if (chl->user[i] == -1)
		{
			chl->user[i] = cs;
			//todo join successful
		}
		i++;
	}
	if (i == MAX_CHANNEL_USER)
		queue_rsp(e, cs, "471", NULL);
}

void	create_channel(t_env *e, char *name, int cs)
{
	size_t i;

	i = 0;
	while (i < MAX_CHANNEL)
	{
		if (e->channels[i].name[0] == '\0')
		{
			e->channels[i].user[0] = cs;
			ft_strcpy(e->channels[i].name, name);
			//todo join successful
		}
		i++;
	}
	if (i == MAX_CHANNEL)
		queue_rsp(e, cs, "405", NULL);
}

t_chl *find_channel(t_env *e, char *name)
{
	size_t i;

	i = 0;
	while (i < MAX_CHANNEL)
	{
		if (ft_strcmp((const char *)e->channels[i].name, name) == 0)
			return (&e->channels[i]);
		i++;
	}
	return (NULL);
}

void cmd_join(t_env *e, char **av, int cs)
{
	size_t	tmp;
	char	**spl;
	char 	**tas;
	t_chl	*chl;

	tmp = ft_strarrlen((const char **) av);
	if (tmp < 2 || tmp > 3)
		return (queue_rsp(e, cs, "461", NULL));
	spl = ft_strsplit(av[1], ',');
	tas = spl;
	while (*tas)
	{
		if (check_channle(*tas) == FALSE)
			queue_rsp(e,cs,"476", NULL);
		chl = find_channel(e,*tas);
		if (chl)
			join_channel(e, chl, cs);
		else
			create_channel(e, *tas, cs);
		tas++;
	}
	ft_strarrdel(&spl);
}