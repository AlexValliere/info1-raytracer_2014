# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/30 14:01:21 by apetit            #+#    #+#              #
#    Updated: 2014/02/17 16:56:15 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang
NAME		= libft.a

SRC			=	srcs/ft_abs.c \
				srcs/ft_atoi.c \
				srcs/ft_bzero.c \
				srcs/ft_chartab2inc.c \
				srcs/ft_dlst_append.c \
				srcs/ft_dlst_del.c \
				srcs/ft_dlst_insert.c \
				srcs/ft_dlst_len.c \
				srcs/ft_dlst_new.c \
				srcs/ft_dlst_prepend.c \
				srcs/ft_is_int.c \
				srcs/ft_isalnum.c \
				srcs/ft_isalpha.c \
				srcs/ft_isascii.c \
				srcs/ft_isdigit.c \
				srcs/ft_isprint.c \
				srcs/ft_isspace.c \
				srcs/ft_itoa.c \
				srcs/ft_lstnew.c \
				srcs/ft_lstdelone.c \
				srcs/ft_lstdelfirst.c \
				srcs/ft_lstdel.c \
				srcs/ft_lstadd.c \
				srcs/ft_lstgetlast.c \
				srcs/ft_lstiter.c \
				srcs/ft_lstswap.c \
				srcs/ft_lstsize.c \
				srcs/ft_memalloc.c \
				srcs/ft_memccpy.c \
				srcs/ft_memchr.c \
				srcs/ft_memcmp.c \
				srcs/ft_memcpy.c \
				srcs/ft_memdel.c \
				srcs/ft_memmove.c \
				srcs/ft_memset.c \
				srcs/ft_power.c \
				srcs/ft_printf/ft_printf.c \
				srcs/ft_printf/ft_printf_fct_1.c \
				srcs/ft_printf/ft_printf_fct_2.c \
				srcs/ft_printf/ft_printf_flags.c \
				srcs/ft_putchar.c \
				srcs/ft_putstr.c \
				srcs/ft_putendl.c \
				srcs/ft_putnbr.c \
				srcs/ft_putchar_fd.c \
				srcs/ft_putstr_fd.c \
				srcs/ft_putendl_fd.c \
				srcs/ft_putnbr_base.c \
				srcs/ft_putnbr_fd.c \
				srcs/ft_putnbr_uint.c \
				srcs/ft_realloc.c \
				srcs/ft_strtolower.c \
				srcs/ft_strtoupper.c \
				srcs/ft_strcat.c \
				srcs/ft_strchr.c \
				srcs/ft_strcmp.c \
				srcs/ft_strcpy.c \
				srcs/ft_strdel_double_sp.c \
				srcs/ft_strdup.c \
				srcs/ft_strdup_delchar.c \
				srcs/ft_strdup_tabtosp.c \
				srcs/ft_strlcat.c \
				srcs/ft_strlen.c \
				srcs/ft_strncat.c \
				srcs/ft_strncmp.c \
				srcs/ft_strncpy.c \
				srcs/ft_strnstr.c \
				srcs/ft_strrchr.c \
				srcs/ft_strstr.c \
				srcs/ft_strnew.c \
				srcs/ft_strdel.c \
				srcs/ft_strclr.c \
				srcs/ft_striter.c \
				srcs/ft_striteri.c \
				srcs/ft_strmap.c \
				srcs/ft_strmapi.c \
				srcs/ft_strequ.c \
				srcs/ft_strnequ.c \
				srcs/ft_strrev.c \
				srcs/ft_strsub.c \
				srcs/ft_strjoin.c \
				srcs/ft_strtrim.c \
				srcs/ft_strsplit.c \
				srcs/ft_tolower.c \
				srcs/ft_toupper.c \
				srcs/get_next_line.c

OBJ			= $(SRC:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ) includes/libft.h
			ar -q $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ -g

.PHONY:		all clean re fclean
