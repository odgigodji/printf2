cmake_minimum_required(VERSION 3.12.3)

project(PRINTF)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(PRINTF
        ft_printf.c
        libft/ft_strlen.c
        libft/ft_atoi.c
        libft/ft_itoa.c
        libft/ft_strrev.c
        libft/ft_isspace.c
        libft/ft_isdigit.c
        libft/ft_putnbr.c
        libft/ft_putstr.c
        libft/ft_putchar.c
        libft/ft_numlen.c
        libft/ft_putstrn.c
        libft/ft_strjoin.c
        libft/ft_toupper.c
        libft/ft_numlen_unsigned.c
        libft/ft_strchr.c
        libft/ft_calloc.c
        libft/ft_bzero.c
        libft/ft_memset.c
        ft_printf_utils.c
        ft_print_p_u.c
        ft_print_d_c.c
        ft_print_x_xup_s.c
        ft_parser_utils.c
        ft_parser.c
        main.c
        )
