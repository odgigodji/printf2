# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namerei <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 20:47:33 by namerei           #+#    #+#              #
#    Updated: 2020/12/22 22:30:16 by namerei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_parser.c ft_parser_utils.c \
		  ft_print_d_c.c ft_print_p_u.c ft_print_x_xup_s.c \
		  ft_printf_utils.c ft_processor.c
OBJ		= $(SRCS:.c=.o)
NAME	= libftprintf.a
HEADER	= ft_printf.h
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I $(HEADER) -c


all: $(NAME)

$(NAME):	$(OBJ) 
			$(MAKE) all -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(CFLAGS) $(SRCS)
			ar rc $(NAME) $(OBJ) 

clean:
			$(RM) $(OBJ)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) fclean -C ./libft

re:		fclean all
