# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 09:35:01 by kuzyilma          #+#    #+#              #
#    Updated: 2025/01/24 17:03:52 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fract-ol.c ft_complex_utils.c ft_coordinate_utils.c mandelbrot.c ft_window_utils.c ft_color_utils.c \
color_shift.c ft_hook_handlers.c fractals.c ft_atod.c julia.c

CC = cc
CFLAGS = -Wall -Werror -Wextra

OSRC = $(SRC:.c=.o)

NAME = fractol

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx-linux/libmlx_Linux.a
LFLAGS= -Lminilibx-linux
LIBS = -lmlx -lX11 -lXext -lm
all: $(NAME)

$(LIBFT):
	make all -C ./libft

$(MINILIBX):
	make all -C ./minilibx-linux/

$(NAME): $(OSRC) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OSRC) $(MINILIBX) $(LIBFT) $(LFLAGS) $(LIBS) -o $(NAME)
	
clean:
	make clean -C ./libft
	rm -f $(OSRC)

fclean: clean
	make fclean -C ./libft
	make clean -C ./minilibx-linux
	rm -f $(NAME) checker

re: fclean all

main: all bonus
	make clean -C ./libft
	rm -f $(OSRC) 
	clear

.PHONY: all clean fclean re main bonus
	
