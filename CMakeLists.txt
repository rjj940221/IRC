cmake_minimum_required(VERSION 3.7)
project(IRC)

set(CMAKE_C_STANDARD 99)

set(SVR_SRC server_src/server.c server_src/irc_server.h irc.h src/exwraper.c server_src/setup.c server_src/receve.c server_src/client.c)
set(CLN_SRC client_src/client.c irc.h src/ipv.c src/exwraper.c)
aux_source_directory(libft LIBFT)

include_directories(libft)

add_executable(client ${CLN_SRC})
add_executable(server ${SVR_SRC})
add_library(libft STATIC ${LIBFT})

link_libraries(client libft)
link_libraries(server libft)