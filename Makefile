# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporcher <mporcher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 09:49:24 by alegay            #+#    #+#              #
#    Updated: 2015/06/13 21:24:44 by mporcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			src/ft_color.c src/ft_print.c src/ft_wolf_3d.c \
				src/ft_key_event.c src/ft_ray_casting.c

NAME = wolf3d
OBJ = $(patsubst %.c, %.o, $(notdir $(SRC)))

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I mlx_lib/ -I libft/includes/
LINKS = -L mlx_lib/ -lmlx -L libft/ -lft
FRAM = -framework OPENGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	make -C mlx_lib/
	gcc -Ofast -g $(FLAGS) -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(LINKS) -Ofast $(FRAM)

clean:
	make -C libft/ clean
	make -C mlx_lib/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	make -C mlx_lib/ clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re