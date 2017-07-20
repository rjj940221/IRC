//
// Created by Robert JONES on 2017/07/20.
//

#include "irc_client.h"

void	add_write_buff(char *data)
{
	g_clt_env.writbuff = ft_strjoin_free_l(g_clt_env.writbuff, data);
}

void	send_write_buff(void)
{
	size_t size;
	char *tmp;
	long re;

	size = (ft_strlen(g_clt_env.writbuff) < BUF_SIZE) ? ft_strlen(g_clt_env.writbuff) : BUF_SIZE;
	tmp = g_clt_env.writbuff;
	re = Xl(-1, send(g_clt_env.svr_sock, tmp, size, 0), "send");
	if (re > 0)
	{
		g_clt_env.writbuff = ft_strsub(g_clt_env.writbuff, (unsigned int)re, size - re);
		ft_strdel(&tmp);
	}
}

void	rcv_data()
{
	ssize_t r;
	char buf[BUF_SIZE + 1];
	char *cmd;

	r = recv(g_clt_env.svr_sock, buf, BUF_SIZE, 0);
	if (r <= 0)
	{
		close_svr_sock();
		printf("lost server connection\n");
	} else
	{
		buf[r] = '\0';
		g_clt_env.readbuff = ft_strjoin_free_l(g_clt_env.readbuff, buf);
		while ((cmd = get_cmd(&g_clt_env.readbuff)) != NULL)
		{
			printf("%s\n",cmd);
			ft_strdel(&cmd);
		}
	}
}