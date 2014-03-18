#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/02/23 23:22:58 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= clang
NAME		= raytracer
SRC			=	main.c \
				draw.c \
				handler.c \
				string.c \
				parser/srcs/parser.c
OBJ			= $(SRC:.c=.o)
MINILIBX	= -L /usr/X11/lib -lmlx -lXext -lX11
CFLAGS		= -Wall -Werror -Wextra
LIBFT_DIR	= ./libft
RM			= rm -rf

all:			make_lib $(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) -L $(LIBFT_DIR)/ -lft $(MINILIBX)

make_lib:
				cd $(LIBFT_DIR) && $(MAKE)

clean:
				cd $(LIBFT_DIR) && $(MAKE) $@
				$(RM) $(OBJ)

fclean:			clean
				cd $(LIBFT_DIR) && $(MAKE) $@
				$(RM) $(NAME)

re:				fclean all

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -I $(LIBFT_DIR)/includes/ -o $@ -g

.PHONY:			all clean re fclean
