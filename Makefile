# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/09/27 11:51:08 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=so_long
NAME_BONUS=so_long_bonus
NAME_MAC=so_long_mac
#NAME_MAC_BONUS=so_long_bonus

SRCS=$(addprefix ${FOLDER}/, \
	ft_so_long.c\
	ft_tools_error.c\
	ft_tools_map.c\
	ft_tools_map_validity.c\
	ft_game_init.c)
SRCS_BOUNS=$(addprefix ${FOLDER}/, \
	ft_so_long_bonus.c\
	ft_tools_error.c\
	ft_tools_maps_memory_bonus.c\
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
#CMLXFLAGS=-lft -lmlx -lXext -lX11 -lm -lbds
CMLXFLAGS_MACOS=-L./$(MLX) -lmlx -framework OpenGL -framework AppKit
#CMLXFLAGS_C=-Imlx -c
RM=rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

mac: $(NAME_MAC)

#bonus_mac: $(NAME_MAC_BONUS)

basic_adventure: 
	bash launch_basic_adventure.sh

$(NAME): $(OBJS)
#	make -C $(MLX)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
#	$(CC) $(CFLAGS) $(CMLXFLAGS) -o $@ $^ $(LIBFT)/libft.a
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a

$(NAME_BONUS): $(OBJS_BONUS)
#	make -C $(MLX)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
#	$(CC) $(CFLAGS) $(CMLXFLAGS) -o $@ $^ $(LIBFT)/libft.a
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a


$(NAME_MAC): $(OBJS)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
	make -s -C $(MLX)
	$(CC) $(CFLAGS) $(CMLXFLAGS_MACOS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a

#$(NAME_MAC): $(OBJS_BONUS)
#	make -C $(MLX)
#	make -C $(LIBFT) bonus
#	$(CC) $(CFLAGS) $(CMLXFLAGS_MACOS) -o $@ $^ $(LIBFT)/libft.a

%.o: %.c
#	$(CC) -c $(CFLAGS) $(CMLXFLAGS_C) -o $@ $< -I $(INCLUDES)
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	make clean -C $(LIBFT)
	make clean -C $(GNL)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

