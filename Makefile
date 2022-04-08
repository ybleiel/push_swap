# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:10:38 by ybleiel           #+#    #+#              #
#    Updated: 2022/04/07 16:32:16 by ybleiel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

SRCS	=  main.c radix_sort.c index_sort.c utils.c small_sort.c cmds/push.c \
			cmds/reverse_rotate.c cmds/rotate.c cmds/swap.c check.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS 	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	
fclean: 
	rm -f $(NAME) $(OBJS) 

clean: 
	rm -f $(OBJS) 

re: fclean all

.PHONY: all fclean clean re 