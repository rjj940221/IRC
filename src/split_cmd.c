//
// Created by Robert JONES on 2017/07/20.
//

#include "../irc.h"

char *get_trail(char *cmd)
{
	char *trail;
	int	ofset;

	ofset = 1;
	while ((trail = ft_strchr(&cmd[ofset], ':')))
	{
		if (*(trail - 1) == ' ')
			return (trail);
	}
	return (trail);
}

char **strarrjoin_str(char **arr, char *str)
{
	size_t tmp;
	char	**re;

	if (!str)
		return (NULL);
	tmp = ft_strarrlen((const char **)arr);
	if (!(re = malloc(sizeof(char *) * (tmp + 2))))
		return (NULL);
	tmp = 0;
	while (arr && arr[tmp])
	{
		re[tmp] = ft_strdup(arr[tmp]);
		tmp++;
	}
	re[tmp++] = ft_strdup(str);
	re[tmp] = NULL;
	return (re);
}

char **split_cmd(char *cmd)
{
	char	**spl;
	char	*pre;
	char	*trail;
	char 	**re;

	if ((trail = get_trail(cmd)))
	{
		pre = ft_strsub(cmd, 0, trail - cmd);
		spl = ft_strsplit(pre, ' ');
		re = strarrjoin_str(spl, trail);
		ft_strarrdel(&spl);
	}
	else
	{
		pre = ft_strdup(cmd);
		re = ft_strsplit(pre, ' ');
	}
	return (re);
}