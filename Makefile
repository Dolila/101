# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jofayard <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/06 11:09:40 by jofayard     #+#   ##    ##    #+#        #
#    Updated: 2018/03/27 17:32:17 by jofayard    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefiles                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofayard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 20:22:16 by jofayard          #+#    #+#              #
#    Updated: 2018/03/06 11:02:00 by jofayard    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror -O3

RM=rm -f

SRC=$(PATH_INC)ft_memset.c \
	$(PATH_INC)ft_bzero.c \
	$(PATH_INC)ft_memcpy.c \
	$(PATH_INC)ft_memccpy.c \
	$(PATH_INC)ft_memmove.c \
	$(PATH_INC)ft_memchr.c \
	$(PATH_INC)ft_memcmp.c \
	$(PATH_INC)ft_memalloc.c \
	$(PATH_INC)ft_memdel.c \
	$(PATH_INC)ft_strlen.c \
	$(PATH_INC)ft_strdup.c \
	$(PATH_INC)ft_strcpy.c \
	$(PATH_INC)ft_strncpy.c \
	$(PATH_INC)ft_strcat.c \
	$(PATH_INC)ft_strncat.c \
	$(PATH_INC)ft_strlcat.c \
	$(PATH_INC)ft_strchr.c \
	$(PATH_INC)ft_strrchr.c \
	$(PATH_INC)ft_strstr.c \
	$(PATH_INC)ft_strnstr.c \
	$(PATH_INC)ft_strcmp.c \
	$(PATH_INC)ft_strncmp.c \
	$(PATH_INC)ft_atoi.c \
	$(PATH_INC)ft_isalpha.c \
	$(PATH_INC)ft_isdigit.c \
	$(PATH_INC)ft_isalnum.c \
	$(PATH_INC)ft_isascii.c \
	$(PATH_INC)ft_isprint.c \
	$(PATH_INC)ft_toupper.c \
	$(PATH_INC)ft_tolower.c \
	$(PATH_INC)ft_strnew.c \
	$(PATH_INC)ft_strdel.c \
	$(PATH_INC)ft_strclr.c \
	$(PATH_INC)ft_striter.c \
	$(PATH_INC)ft_striteri.c \
	$(PATH_INC)ft_strmap.c \
	$(PATH_INC)ft_strmapi.c \
	$(PATH_INC)ft_strequ.c \
	$(PATH_INC)ft_strnequ.c \
	$(PATH_INC)ft_strsub.c \
	$(PATH_INC)ft_strjoin.c \
	$(PATH_INC)ft_strtrim.c \
	$(PATH_INC)ft_strsplit.c \
	$(PATH_INC)ft_itoa.c \
	$(PATH_INC)ft_intlen.c \
	$(PATH_INC)ft_islower.c \
	$(PATH_INC)ft_isupper.c \
	$(PATH_INC)ft_putchar.c \
	$(PATH_INC)ft_putstr.c \
	$(PATH_INC)ft_putendl.c \
	$(PATH_INC)ft_putnbr.c \
	$(PATH_INC)ft_putchar_fd.c \
	$(PATH_INC)ft_putstr_fd.c \
	$(PATH_INC)ft_putendl_fd.c \
	$(PATH_INC)ft_putnbr_fd.c \
	$(PATH_INC)ft_alloc_str.c \
	$(PATH_INC)get_next_line.c \

HDR=$(PATH_HDR)libft.h \
	$(PATH_HDR)get_next_line.h \

PATH_INC=

PATH_HDR=

OBJ=$(PATH_INC)$(SRC:.c=.o)

$(NAME): 
	gcc $(CFLAGS) -c $(SRC) $(HDR)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

fdf:
	gcc 2main.c libmlx.a libft.a -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJ) *.gch

fclean: clean
	$(RM) $(NAME)

re: fclean all
