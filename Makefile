# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcourtin <mcourtin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 20:39:09 by aabda             #+#    #+#              #
#    Updated: 2023/09/29 15:36:35 by mcourtin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
MLX		= ./mlx/libmlx.a
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -finline-functions -fvectorize -fslp-vectorize -ffast-math -falign-functions -funroll-loops -fstrict-aliasing -fomit-frame-pointer -flto -Ofast -O1 -O2 -Os -O3
MFLAGS	= -L./mlx -lmlx -framework OpenGL -framework AppKit

SRC_DIR = ./src/
SRC_LIST = $(CORE) $(PARSING) $(UTILS)
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

CORE_DIR = core/
CORE_SRC = cub3d.c render.c render2.c init_img.c moves.c ray.c raycast.c \
	init_texture.c ray_vertical.c
CORE = $(addprefix $(CORE_DIR), $(CORE_SRC))

PARSING_DIR = parsing/
PARSING_SRC = fill_struct_map.c fill_struct_map2.c create_map_in_struct.c
PARSING = $(addprefix $(PARSING_DIR), $(PARSING_SRC))

UTILS_DIR = utils/
UTILS_SRC = libft_utils.c libft_utils2.c utils.c map_utils.c errors.c \
	mlx_hook.c check.c player.c libft_utils3.c
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_SRC))

OBJS = $(SRC:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	make -sC ./mlx

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(MFLAGS) -o $(NAME) $(OBJS)

norm:
	norminette -R CheckDefine

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean -C ./mlx

re: fclean all

rel: clean all

.PHONY:	all clean fclean re norm