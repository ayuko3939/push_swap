# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohasega <yohasega@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 19:04:31 by yohasega          #+#    #+#              #
#    Updated: 2024/08/17 11:49:00 by yohasega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c quick_sort.c quick_sort_2pivots.c simple_sort.c sort_helper.c \
	   search.c sort_stack_b.c \
	   init.c list.c utils.c validate.c \
	   operation/operat_push.c operation/operat_swap.c \
	   operation/operat_rotate.c operation/operat_reverse_rotate.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all