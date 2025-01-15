# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 16:23:34 by sithomas          #+#    #+#              #
#    Updated: 2025/01/15 15:01:27 by sithomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

INC = -Iincludes

SRCFOLDER = src/

OBJFOLDER = objs/

SRC_LIST = ps_utils.c \
	stack_lst_utils.c \
	stack_lst_utils_2.c \
	parse.c \
	parse_2.c \
	freefile.c \
	radix.c \
	main.c \
	
SRC = $(addprefix $(SRCFOLDER), $(SRC_LIST))

SRC_OBJS = $(patsubst $(SRCFOLDER)%.c, $(OBJFOLDER)%.o, $(SRC))

LIBS = libft/libft.a

all: git libft $(NAME)

git:
	@git submodule update --init --recursive --remote

libft:
	@$(MAKE) -s -C libft

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) $(LIBS) -o $@
	@echo 'push_swap created'

$(OBJFOLDER)%.o: $(SRCFOLDER)%.c Makefile includes
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) clean -s -C libft
	@rm -rf $(OBJFOLDER)
	@echo 'push swap objs cleaned'

fclean: clean
	@rm -f $(NAME) libft/libft.a
	@echo 'push swap all cleaned'

re : fclean all

.PHONY: all clean fclean re git libft