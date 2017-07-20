//
// Created by Robert JONES on 2017/07/20.
//

#include "irc_server.h"

t_chl *find_channel(t_env *e, char *name, int *chlidx)
{
	size_t i;

	i = 0;
	*chlidx = -1;
	while (i < MAX_CHANNEL)
	{
		if (ft_strcmp((const char *)e->channels[i].name, name) == 0)
		{
			*chlidx = (int)i;
			return (&e->channels[i]);
		}
		i++;
	}
	return (NULL);
}

t_bool	user_in_chl(t_chl *chl, int user_id)
{
	size_t i;

	i = 0;
	while (i < MAX_CHANNEL_USER)
		if (chl->user[i++] == user_id)
			return (TRUE);
	return (FALSE);
}