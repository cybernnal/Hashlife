cmake_minimum_required(VERSION 3.6)
project(table)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    libft/ft_atoi.c
    libft/ft_atoidbl.c
    libft/ft_bzero.c
    libft/ft_countchiffres.c
    libft/ft_freetab.c
    libft/ft_isalnum.c
    libft/ft_isalpha.c
    libft/ft_isascii.c
    libft/ft_isdigit.c
    libft/ft_isnb.c
    libft/ft_isprint.c
    libft/ft_itoa.c
    libft/ft_lstadd.c
    libft/ft_memalloc.c
    libft/ft_memccpy.c
    libft/ft_memchr.c
    libft/ft_memcmp.c
    libft/ft_memcpy.c
    libft/ft_memdel.c
    libft/ft_memmove.c
    libft/ft_memset.c
    libft/ft_nbword.c
    libft/ft_print_tab.c
    libft/ft_printlst.c
    libft/ft_putchar.c
    libft/ft_putchar_fd.c
    libft/ft_putendl.c
    libft/ft_putendl_fd.c
    libft/ft_putnbr.c
    libft/ft_putnbr_fd.c
    libft/ft_putstr.c
    libft/ft_putstr_fd.c
    libft/ft_sqrt.c
    libft/ft_strcat.c
    libft/ft_strchr.c
    libft/ft_strclr.c
    libft/ft_strcmp.c
    libft/ft_strcpy.c
    libft/ft_strdel.c
    libft/ft_strdup.c
    libft/ft_strdupnfree.c
    libft/ft_strequ.c
    libft/ft_striter.c
    libft/ft_striteri.c
    libft/ft_strjoin.c
    libft/ft_strlcat.c
    libft/ft_strlen.c
    libft/ft_strmap.c
    libft/ft_strmapi.c
    libft/ft_strncat.c
    libft/ft_strncmp.c
    libft/ft_strncpy.c
    libft/ft_strnequ.c
    libft/ft_strnew.c
    libft/ft_strnstr.c
    libft/ft_strrchr.c
    libft/ft_strrevchr.c
    libft/ft_strsplit.c
    libft/ft_strstr.c
    libft/ft_strsub.c
    libft/ft_strtrim.c
    libft/ft_tolower.c
    libft/ft_toupper.c
    libft/get_next_line.c
    libft/get_next_line.h
    libft/libft.h
    convert_rule.c)

include_directories(libft)

add_executable(table ${SOURCE_FILES})