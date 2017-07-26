SVR_NAME = server
CLN_NAME = client
INCLUDES = -I libft
C_FLAGS = -g3 -Wall -Werror -Wextra $(INCLUDES)
L_FLAGS = -L libft -lft -lncurses
CC = gcc

SVR_OBJ = build_svr/client.o build_svr/cmd_join.o build_svr/cmd_names.o\
		  build_svr/cmd_nick.o build_svr/cmd_part.o build_svr/cmd_privmsg.o\
		  build_svr/exwraper.o build_svr/ipv.o build_svr/main_loop.o\
		  build_svr/receve.o build_svr/responce.o build_svr/rpl_namrply.o\
		  build_svr/server.o build_svr/setup.o build_svr/support.o

CLN_OBJ = build_cln/client.o build_cln/cmd_join.o build_cln/cmd_leave.o\
		  build_cln/cmd_nick.o build_cln/cmd_privmsg.o build_cln/cmd_who.o\
		  build_cln/connect.o build_cln/data_transfer.o build_cln/exwraper.o\
		  build_cln/ft_search_builtin.o build_cln/input_handler.o\
		  build_cln/ipv.o build_cln/support.o build_cln/setup.o

COM_OBJ = build/check_channle_name.o build/check_nick.o build/get_cmd.o\
		  build/split_cmd.o 

all : lft $(SVR_NAME) $(CLN_NAME)

build_svr/%.o : server_src/%.c server_src/irc_server.h irc.h
	@mkdir -p build_svr
	@$(CC) $(C_FLAGS) -c $< -o $@
	@echo "\033[92m$@\033[0m"

build_cln/%.o : client_src/%.c client_src/irc_client.h irc.h
	@mkdir -p build_cln
	@$(CC) $(C_FLAGS) -c $< -o $@
	@echo "\033[92m$@\033[0m"

build/%.o :  src/%.c irc.h
	@mkdir -p build
	@$(CC) $(C_FLAGS) -c $< -o $@
	@echo "\033[92m$@\033[0m"

lft:
	@echo "making libft"
	@make -C libft

$(SVR_NAME) : $(SVR_OBJ) $(COM_OBJ)
	@$(CC) $^ $(L_FLAGS) -o $(SVR_NAME)
	@echo "\033[92m$@\033[0m"

$(CLN_NAME) : $(CLN_OBJ) $(COM_OBJ)
	@$(CC) $^ $(L_FLAGS) -o $(CLN_NAME)
	@echo "\033[92m$@\033[0m"

clean:
	@\rm -rf build_svr
	@\rm -rf build_cln
	@\rm -rf build
	@\rm -rf $(SVR_NAME).dSYM
	@\rm -rf $(CLN_NAME).dSYM
	@make -C libft clean

fclean: clean
	@rm -f  $(SVR_NAME)
	@rm -f $(CLN_NAME)
	make -C libft fclean

re: fclean all
