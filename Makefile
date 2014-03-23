#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/03/21 21:12:02 by qde-vial         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	raytracer
SRC			=	main.c		\
				calc.c		\
				rotate.c	\
				inter_obj.c	\
				draw.c		\
				handler.c	\
				string.c	\
				nbrs.c		\
				parser.c	\
				scenes.c	\
				objs.c		\
				gnl.c		\
				thread.c
SRCS		=	$(addprefix srcs/, $(SRC))
OBJS		=	$(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Iincs -g
LIBS		=	-L/usr/X11/lib -lmlx -lXext -lX11 -lpthread
RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
