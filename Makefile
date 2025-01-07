# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 16:23:34 by sithomas          #+#    #+#              #
#    Updated: 2025/01/07 10:38:18 by sithomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC = push_swap.c \

INC = push_swap.h \

OFILES = $(SRC:.c=.o)

NAME = push_swap

all: git libft $(NAME)

libft:
	$(MAKE) -C libft

bonus:

git:
	git submodule update --init --recursive

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c $(INC) Makefile minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@ libft/libft.a

clean:
	$(MAKE) clean -C libft
	rm -f *.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re : fclean all

.PHONY: all clean fclean re