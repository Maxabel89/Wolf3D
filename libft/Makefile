#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 14:13:08 by mporcher          #+#    #+#              #
#    Updated: 2015/06/02 14:39:09 by mporcher         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= gcc

NAME		= libft.a

SRC 		= ft_atoi.c ft_bzero.c ft_isalpha.c ft_isascii.c ft_strrchr.c \
	ft_isdigit.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c ft_strcat.c ft_strchr.c \
	ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c \
	ft_strnstr.c ft_strstr.c ft_tolower.c  ft_toupper.c ft_strncpy.c \
	ft_isprint.c ft_strcmp.c ft_memccpy.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_isalnum.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strtrim.c ft_strsub.c \
	ft_strsplit.c ft_itoa.c ft_putnbr.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c \
	ft_lstadd.c ft_strupper.c ft_strlower.c ft_strchr_idx.c ft_putexit.c \
	ft_swap.c ft_strisalpha.c ft_str_isnumber.c ft_str_isempty.c \
	get_next_line.c \
	ft_printf.c parse.c \
	s_flag.c str_tools4.c \
	x_flag.c c_flag.c \
	parsing.c str_tools.c tools.c \
	d_flag.c o_flag.c parsing_arg.c \
	str_tools2.c u_flag.c flag_list.c \
	p_flag.c percent_flag.c \
	str_tools3.c wtchar_tools.c


OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): ./libft.h $(SRC)
	$(CC) $(CFLAGS) -I . -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
