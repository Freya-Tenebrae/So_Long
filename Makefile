# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/09/29 19:35:28 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=so_long
NAME_BONUS=so_long_bonus

SRCS=$(addprefix ${FOLDER}/, \
	ft_so_long.c\
	ft_tools_error.c\
	ft_tools_map.c\
	ft_tools_map_validity.c\
	ft_game_init.c\
	ft_tools_images_management.c)
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
CMLXFLAGS=-L$(MLX) -I$(MLX) -lXext -lX11 -lm -lz
CMLXFLAGS_C=-I$(MLX)
RM=rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

basic_adventure: 
	bash launch_basic_adventure.sh

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
	make -C $(MLX)
	$(CC) $(CFLAGS) $(CMLXFLAGS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	make -C $(GNL) bonus
	make -C $(MLX)
	$(CC) $(CFLAGS) $(CMLXFLAGS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a $(MLX)/libmlx_Linux.a

%.o: %.c
	$(CC) -c $(CFLAGS) $(CMLXFLAGS_C) -o $@ $< -I $(INCLUDES)

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

