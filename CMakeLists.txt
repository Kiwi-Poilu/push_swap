cmake_minimum_required(VERSION 3.16)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap srcs/main.c srcs/utils.c srcs/operations.c srcs/get_infos.c srcs/utils2.c srcs/ft_strtol.c srcs/compensate.c srcs/run.c srcs/run2.c srcs/sort.c srcs/get_infos2.c)
