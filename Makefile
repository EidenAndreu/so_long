# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 12:05:10 by ereinald          #+#    #+#              #
#    Updated: 2023/09/11 13:02:03 by ereinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDE = .
LIBFT = libft
GET_NEXT_LINE = get_next_line
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE) -I$(LIBFT) -I$(GET_NEXT_LINE) -g
RM = rm -f

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

# Lista de archivos fuente
SRC_FILES = ft_check_map_others.c ft_check_map_structure.c ft_draw_map.c \
			ft_draw.c ft_init_game.c ft_init_utils.c ft_keys.c ft_movements.c \
			ft_parse_map.c ft_utils.c so_long.c

# Lista de objetos a compilar
OBJ = $(SRC_FILES:.c=.o)

HDR_FILES = so_long.h

all: $(NAME)

$(NAME): $(OBJ) $(HDR_FILES) Makefile
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re