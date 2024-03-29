#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/03/26 17:42:39 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	raytracer
SRC			=	main.c		\
				calc.c		\
				light.c		\
				shadow.c	\
				colors.c	\
				rotate.c	\
				inter_obj.c	\
				lt_obj.c	\
				geom.c		\
				draw.c		\
				handler.c	\
				string.c	\
				nbrs.c		\
				parser.c	\
				chk_param.c \
				scenes.c	\
				objs.c		\
				gnl.c		\
				damier.c
SRCS		=	$(addprefix srcs/, $(SRC))
OBJS		=	$(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Iincs
LIBS		=	-L/usr/X11/lib -lmlx -lXext -lX11 -lm
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
