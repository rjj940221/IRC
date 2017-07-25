cmake_minimum_required(VERSION 3.7)
project(IRC)

set(CMAKE_C_STANDARD 99)

set(SVR_SRC
        server_src/server.c
        server_src/irc_server.h
        irc.h
        server_src/setup.c
        server_src/receve.c
        server_src/client.c
        server_src/main_loop.c
        server_src/cmd_nick.c
        server_src/responce.c
        server_src/cmd_join.c
        server_src/cmd_part.c
        server_src/cmd_names.c
        server_src/support.c
        server_src/rpl_namrply.c
        server_src/cmd_privmsg.c
        server_src/ipv.c
        server_src/exwraper.c)

set(CLN_SRC
        client_src/client.c
        irc.h
        client_src/ft_search_builtin.c
        client_src/irc_client.h
        client_src/support.c
        client_src/cmd_nick.c
        client_src/connect.c
        client_src/data_transfer.c
        client_src/cmd_join.c
        client_src/cmd_leave.c
        client_src/cmd_who.c
        client_src/cmd_privmsg.c
        client_src/input_handler.c
        client_src/ipv.c
        client_src/exwraper.c)

set(COM_SRC
        src/check_nick.c
        src/check_channle_name.c
        src/split_cmd.c
        src/get_cmd.c)
aux_source_directory(libft LIBFT)

include_directories(libft)

find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )


add_executable(client ${CLN_SRC} ${COM_SRC})
add_executable(server ${SVR_SRC} ${COM_SRC})
add_library(libft STATIC ${LIBFT})

target_link_libraries(client libft)
target_link_libraries(client ${CURSES_LIBRARIES})
target_link_libraries(server libft)