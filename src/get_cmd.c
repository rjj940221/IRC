//
// Created by Robert JONES on 2017/07/20.
//

#include "../irc.h"

char *get_cmd(char **read_buff)
{
	char	*crln;
	char	*tmp;
	char	*cmd;
	size_t	off;

	off = 0;
	cmd = NULL;
	while ((crln = ft_strchr(&(*read_buff[off]), '\r')))
	{
		if (*(crln + 1) == '\n')
		{
			tmp = *read_buff;
			cmd = ft_strsub(*read_buff, 0, crln - tmp - 1);
			*read_buff = ft_strdup(crln + 2);
			ft_strdel(&tmp);
			return (cmd);
		}
		off = crln - *read_buff;
	}
	return (cmd);
}