# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namerei <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 20:47:33 by namerei           #+#    #+#              #
#    Updated: 2020/12/19 17:57:50 by namerei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_processor.c ft_printf.c ft_parser.c ft_putchar1.c
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
