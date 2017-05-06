# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 00:09:09 by ksaetern          #+#    #+#              #
#    Updated: 2017/05/03 19:56:13 by ksaetern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ftdb

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

SRCS	= 	main.c \
			create.c \
			createformat.c \
			add.c \
			search.c \
			searchstore.c \
			searchmenu.c \
			destroy.c \
			utility.c \

OBJ =		${SRCS:.c=.o}

INCLUDE	=	-I ftdb.h -I ./libft/ -L ./libft -lft

all: $(NAME)

$(OBJ): $(SRCS)
		@$(CC) $(FLAG) -c $*.c

$(NAME): $(OBJ)
		@make all -C libft
		@$(CC) $(FLAG) $(INCLUDE) $(OBJ) -o $(NAME)
		@echo " █████▒  ▒██████▒ █████▄  ▄▄▄▄       ▄████▄   ██▀███  ▓█████ ▄▄▄     ▒██████▒ ▓█████ ▓█████▄ ";
		@echo "▓██     ░  ██▒   ▒██   █▌ █████▄    ▒██▀ ▀█  ▓██   █ ▒▓█   ▀▒████▄   ▓  ██▒ ▓ ▓█   ▀ ▒██▀ ██▌";
		@echo "▒████░  ▒ ▓██░   ░██   █▌ ██  ▄██   ▒▓█    ▄ ▓██  ▄█ ▒▒███  ▒██  ▀█▄ ▒ ▓██░ ▒ ▒███   ░██   █▌";
		@echo "░▓█▒    ░ ▓██▓ ░ ░▓█▄  ▒▌ ██░█▀     ▒▓▓▄ ▄██▒▒██▀▀█▄  ▒▓   ▄░██▄▄▄▄██░ ▓██▓ ░ ▒▓   ▄ ░▓█▄  ░▌";
		@echo "░▒█░      ▒██▒   ░▒████▓  ▓█  ▀█▓   ▒ ▓███▀ ░░██   ██▒░▒████▒▓█   ▓██▒ ▒██▒ ░ ░▒████▒░▒████▓ ";
		@echo " ▒ ░      ▒ ░░            ▒▓███▀▒   ░ ░▒ ▒  ░░ ▒   ▒▓░░░ ▒░ ░▒▒   ▓▒█░ ▒ ░░   ░░ ▒░ ░        ";
		@echo " ░          ░     ░ ▒  ▒  ░▒   ░      ░  ▒     ░▒   ▒░ ░ ░  ░ ▒   ▒▒ ░   ░     ░ ░  ░ ░ ▒  ▒ ";
		@echo " ░ ░      ░       ░ ░  ░  ░    ░    ░          ░░   ░    ░    ░   ▒    ░         ░    ░ ░  ░ ";
		@echo "                    ░     ░         ░ ░         ░        ░  ░     ░  ░           ░  ░   ░    ";
		@echo "                  ░            ░    ░                                                 ░      ";

clean:
		@make clean -C libft
		@/bin/rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
