# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuriel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:58:05 by amuriel           #+#    #+#              #
#    Updated: 2021/01/27 14:21:20 by amuriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# game
GAME        = cub3D

SRC		    = main.c \
                gnl/get_next_line.c gnl/get_next_line_utils.c
SRCS		= $(addprefix srcs/, $(SRC))

OBJS		= $(SRCS:.c=.o)

# include
INC         = -I ./ -I ./libft -I ./ft_printf -I ./gnl

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
