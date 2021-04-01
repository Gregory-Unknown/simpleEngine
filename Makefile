# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esobchak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/29 18:24:15 by esobchak          #+#    #+#              #
#    Updated: 2021/04/01 16:13:55 by esobchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GAME        = cub3D

SRC		    = main.c \
            	gnl/get_next_line.c gnl/get_next_line_utils.c parser.c \
				check_map.c parser_color.c parser_utils.c parser_texture.c \
				parser_resolution.c init.c init_player.c key_utils.c screenshot.c \
				init_sprites.c sprite.c textures.c raycasting.c utils.c move_player.c
SRCS		= $(addprefix srcs/, $(SRC))

OBJS		= $(SRCS:.c=.o)

# include
INC         = -I ./cub3d.h -I ./libft -I ./ft_printf -I ./gnl

# flags
FLAGS       = -Wall -Wextra -Werror -g

# libft library link
LIBFT       = -L libft -lft

# mlx library link
MLX         = -I minilibx -L minilibx-linux -lmlx

# additional system libraries
SYS         = -lXext -lX11 -lbsd -lm

all:$(GAME)

$(GAME):
	@make -C ./libft
	@make -C ./minilibx-linux
	gcc ${FLAGS} ${SRCS} ${LIBFT} ${MLX} ${SYS} -o ${GAME}

# mlx does not have a clean equivalent
# mlx clean behaves similar to fclean
clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

# mlx clean behaves similar to fclean
fclean: clean
	@/bin/rm -f $(GAME)
	@/bin/rm -f cub3D.bmp
	@make fclean -C ./libft
	@make clean -C ./minilibx-linux

re: fclean all

norm :
	@norminette *.c *.h ./libft/*.c ./libft/*.h

screen : $(NAME)
	./$(NAME) cub3d.cub --save
	open screen.bmp

.PHONY: all clean fclean re norm run screen
