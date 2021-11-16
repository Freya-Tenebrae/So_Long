# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/10/23 15:01:21 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=so_long
NAME_BONUS=so_long_bonus

SRCS=$(addprefix ${FOLDER}/, \
	ft_so_long.c\
	ft_tools_enemies.c\
	ft_tools_exit.c\
	ft_tools_get_path.c\
	ft_tools_images_management.c\
	ft_tools_map.c\
	ft_tools_map_validity.c\
	ft_tools_maps.c\
	ft_tools_movements.c\
	ft_tools_select_wall.c\
	ft_tools_tiles.c)
SRCS_BONUS=$(addprefix ${FOLDER}/, \
	ft_so_long_bonus.c\
	ft_tools_enemies.c\
	ft_tools_exit.c\
	ft_tools_get_path.c\
	ft_tools_images_management.c\
	ft_tools_map.c\
	ft_tools_map_validity_bonus.c\
	ft_tools_maps.c\
	ft_tools_movements.c\
	ft_tools_movements_enemies.c\
	ft_tools_select_wall.c\
	ft_tools_tiles.c\
	ft_tools_update_frame.c)
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

INCLUDES=includes
FOLDER=srcs

NAME_LIBFT=libft
NAME_GNL=get_next_line
LIBFT=includes/libft
GNL=includes/gnl
MLX=includes/mlx

CC=clang -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
CMLXFLAGS= -L/usr/lib -lXext -lX11 -L$(MLX) -lm -lz
RM=rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	make -C $(GNL)
	make -C $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(CMLXFLAGS) $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	make -C $(GNL)
	make -C $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(CMLXFLAGS) $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	make clean -C $(LIBFT)
	make clean -C $(GNL)
	make clean -C $(MLX)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus
