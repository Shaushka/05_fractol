# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/07 15:23:01 by mguillon          #+#    #+#              #
#    Updated: 2015/09/22 14:42:25 by mguillon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = color.c \
	  douady.c \
	  julia.c \
	  mandelbrot.c \
	  expose_hook.c \
	  new_image.c \
	  fill_image.c \
	  ft_pixelput_img.c \
	  isfractal.c \
	  key_hook.c \
	  mouse_hook.c \
	  main.c

MLX_DIR = ./mlx

MLX = $(MLX_DIR)/libmlx.a -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC := $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I libft/ -I includes/ -g

all: $(NAME)

$(NAME): $(SRC) Makefile includes/fractol.h
	make -C libft/
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRC) -L libft/ -lft -lm $(MLX) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	make -C $(MLX_DIR) clean
	@rm -f $(NAME)

re: fclean all
