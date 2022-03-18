# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:10:38 by ybleiel           #+#    #+#              #
#    Updated: 2022/03/15 14:46:43 by ybleiel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

SRCS	=  main.c sort.c utils.c cmds/push.c \
			cmds/reverse_rotate.c cmds/rotate.c cmds/swap.c \

OBJS	= $(SRCS:.c=.o)

HEADER	= push_swap.h

CC		= gcc

CFLACS 	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLACS) $^ -o $(NAME)
	
fclean: 
	rm -f $(NAME) $(OBJS) 

clean: 
	rm -f $(OBJS) 

re: fclean all

.PHONY: all fclean clean re 