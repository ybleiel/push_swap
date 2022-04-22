# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 13:10:38 by ybleiel           #+#    #+#              #
#    Updated: 2022/04/20 11:43:25 by ybleiel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= push_swap

SRCS	=  main.c radix_sort.c index_sort.c utils.c small_sort.c cmds/push.c \
			cmds/reverse_rotate.c cmds/rotate.c cmds/swap.c check.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS 	= -Wall -Werror -Wextra

YELLOW=\033[1;33m
NC=\033[0m
GREEN=\033[0;32m
RED=\033[0;31m

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "${YELLOW}$(NAME) created ${NC}"
	
fclean: 
	rm -f $(NAME) $(OBJS)
	@echo "${RED}executable cleaned${NC}"

clean: 
	rm -f $(OBJS)
	@echo "${GREEN}objects cleaned${NC}"

re: fclean all

.PHONY: all fclean clean re 