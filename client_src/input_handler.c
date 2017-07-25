//
// Created by rojones on 2017/07/25.
//

#include "irc_client.h"

void insert_char(int c, char *line)
{
	size_t ridx;

	ridx = IN_BUFF -2;
	while (--ridx > g_clt_env.idx)
	{
		line[ridx + 1] = line[ridx];
	}
	line[g_clt_env.idx] = (char)c;
}

void handle_case(int c, char *line)
{
	if (c == KEY_BACKSPACE && g_clt_env.idx > 0)
		line[--g_clt_env.idx] = '\0';
	else if(c == KEY_LEFT)
		g_clt_env.idx--;
	else if (c == KEY_RIGHT && line[g_clt_env.idx])
		g_clt_env.idx++;

}

void	send_process_cmd(char *line)
{
	g_clt_env.idx = 0;
	search_builin(line);
	wattron(g_clt_env.winrsp, COLOR_PAIR(4));
	wprintw(g_clt_env.winrsp, "%s\n", line);
	wattroff(g_clt_env.winrsp, COLOR_PAIR(4));
	bzero(line, IN_BUFF);
	wclear(g_clt_env.wincmd);
	wrefresh(g_clt_env.wincmd);
	return_cmd();
}

void	input_handler(int c)
{
	static char line[IN_BUFF];
	static int entered = 0;

	if (c == '\n')
	{
		entered = 0;
		send_process_cmd (line);
	}
	else if (entered++ < IN_BUFF - 1 && isprint(c))
	{
		if (line[g_clt_env.idx] == '\0')
			line[g_clt_env.idx++] = (char) c;
		else
			insert_char(c, line);
	}
	else
		handle_case(c,line);
	wclear(g_clt_env.wincmd);
	mvwprintw(g_clt_env.wincmd,0,0,line);
	wmove(g_clt_env.wincmd, 0, (int)g_clt_env.idx);
	wrefresh(g_clt_env.wincmd);
}