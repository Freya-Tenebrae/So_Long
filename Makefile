# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/10/01 16:55:48 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=so_long
NAME_MAC=so_long_mac_version
NAME_BONUS=so_long_bonus
NAME_BONUS_MAC=so_long_bonus_mac_version

SRCS=$(addprefix ${FOLDER}/, \
	ft_so_long.c\
	ft_tools_error.c\
	ft_tools_maps.c\
	ft_tools_map.c\
	ft_tools_map_validity.c\
	ft_game_init.c\
	ft_tools_draw_collectible.c\
	ft_tools_draw_exit.c\
	ft_tools_draw_player.c\
	ft_tools_draw_scene.c\
	ft_tools_draw_wall.c\
	ft_tools_images_management.c)
SRCS_BOUNS=$(addprefix ${FOLDER}/, \
	ft_so_long_bonus.c\
	ft_tools_error.c\
	ft_tools_maps.c\
	ft_tools_map.c\
	ft_tools_map_validity_bonus.c\
	ft_game_init_bonus.c)
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BOUNS:.c=.o)

INCLUDES=includes
FOLDER=srcs

NAME_LIBFT=libft
NAME_GNL=get_next_line
LIBFT=$(addprefix ${INCLUDES}/, libft)
GNL=$(addprefix ${INCLUDES}/, gnl)
MLX=$(addprefix ${INCLUDES}/, mlx)

CC=gcc -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
CMLXFLAGS=-L$(MLX) -I$(MLX) -lXext -lX11 -lm -lz
CMLXFLAGS_MAC=-L$(MLX) -l$(MLX) -framework OpenGL AppKit
CMLXFLAGS_C=-I$(MLX)
RM=rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

basic_adventure: bonus
	bash launch_basic_adventure.sh

mac: $(NAME_MAC)

mac_bonus: $(NAME_BONUS_MAC)

basic_adventure_mac: mac_bonus
	bash launch_basic_adventure.sh

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
	make -s -C $(MLX)
	$(CC) $(CFLAGS) $(CMLXFLAGS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
	make -s -C $(MLX)
	$(CC) $(CFLAGS) $(CMLXFLAGS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

$(NAME_MAC): $(OBJS)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
	make -s -C $(MLX)
	$(CC) $(CFLAGS) $(CMLXFLAGS_MAC) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx.a

$(NAME_BONUS_MAC): $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
	make -s -C $(MLX)
	$(CC) $(CFLAGS) $(CMLXFLAGS_MAC) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlxs.a

%.o: %.c
	$(CC) -c $(CFLAGS) $(CMLXFLAGS_C) -o $@ $< -I $(INCLUDES)

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

