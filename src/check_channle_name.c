//
// Created by rojones on 2017/07/18.
//

#include "../irc.h"

t_bool check_channle(char *name)
{
	if (!name || ft_strlen(name) > CHANNEL_NAME)
		return (FALSE);
	if (ft_strchr(name, ' ') || ft_strchr(name, 7) ||
			(name[0] != '#' && name[0] != '&'))
		return (FALSE);

	return (TRUE);
}