cmake_minimum_required(VERSION 3.12.3)

project(PRINTF)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(PRINTF
        ft_printf.c
        ft_parser.c
        libft/ft_strlen.c
        libft/ft_atoi.c
        libft/ft_isspace.c
        libft/ft_isdigit.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_putchar.c
        libft/ft_numlen.c
        libft/ft_putstrn.c
        libft/ft_strjoin.c
        libft/ft_toupper.c
        libft/ft_putnbr_unsigned.c
        libft/ft_numlen_unsigned.c
        libft/ft_strchr.c
        libft/ft_calloc.c
        libft/ft_bzero.c
        ft_processor.c
        main.c
        )
