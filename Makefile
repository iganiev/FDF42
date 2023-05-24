# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 13:31:31 by iganiev           #+#    #+#              #
#    Updated: 2023/05/17 20:20:45 by iganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c validate_map.c read_map.c draw_map.c colors.c map_manipulation.c \
		utils.c mlx_functions.c exit_handle.c bonus_key_hooks.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = cd libft && make

MLX = cd mlx && make

MYPRINTF = cd printf42 && make

$(NAME): $(OBJ)
		$(LIB)
		$(MYPRINTF)
		$(MLX)
		gcc $(OBJ)  libft/libft.a printf42/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# -Lmlx -lmlx
# -framework OpenGL -framework AppKit

all: $(NAME)

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C mlx
		cd libft && make clean
		cd printf42 && make clean
fclean: clean
		rm -f $(NAME)
		cd libft && make fclean
		cd printf42 && make fclean
re:		fclean all
		cd libft && make fclean && make all
		cd printf42 && make fclean && make all

.PHONY:	all clean fclean re