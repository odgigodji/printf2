# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namerei <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 20:47:33 by namerei           #+#    #+#              #
#    Updated: 2020/12/16 21:11:00 by namerei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_processor.c ft_printf.c ft_parcer.c 
OBJ		= $(SRCS:.c=.o)
NAME	= libftprintf.a
HEADER	= ft_printf.h
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o :
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I$(HEADER)

all: $(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(MAKE) -C ./libft
			ar rcs $(NAME) $(OBJ) libft/*.o

clean:
			$(RM) $(OBJ)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) fclean -C ./libft

re:		fclean all
