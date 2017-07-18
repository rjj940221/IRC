//
// Created by Robert JONES on 2017/07/18.
//

#include "../irc.h"

int ft_isspecial(int c)
{
	if (c == '-' || c == '[' || c ==  ']' || c ==  '\\'
		|| c ==  '`' || c ==  '^' || c ==  '{' || c == '}')
		return (1);
	return (0);
}

int	check_nick(char *nick)
{
	char	*pt;

	pt = nick;
	if (ft_strlen(nick) > 9)
		return (0);
	while (pt && *pt)
	{
		if (ft_isspecial(*pt) || ft_isalnum(*pt))
			pt++;
		else
			return (0);
	}
	return (1);
}