# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/10/11 14:09:14 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=so_long
NAME_MAC=so_long_mac_version
NAME_BONUS=so_long_bonus
NAME_BONUS_MAC=so_long_bonus_mac_version

SRCS=$(addprefix ${FOLDER}/, \
	ft_so_long.c\
	ft_tools_exit.c\
	ft_tools_get_path.c\
	ft_tools_images_management.c\
	ft_tools_map.c\
	ft_tools_map_validity.c\
	ft_tools_maps.c\
	ft_tools_movements.c\
	ft_tools_select_wall.c\
	ft_tools_tiles.c)
SRCS_BOUNS=$(addprefix ${FOLDER}/, \
	ft_so_long.c\
	ft_tools_exit.c\
	ft_tools_get_path.c\
	ft_tools_images_management.c\
	ft_tools_map.c\
	ft_tools_map_validity_bonus.c\
	ft_tools_maps.c\
	ft_tools_movements.c\
	ft_tools_select_wall.c\
	ft_tools_tiles.c)
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
	# gcc srcs/ft_so_long.c srcs/ft_tools_movements.c srcs/ft_tools_exit.c srcs/ft_tools_get_path.c srcs/ft_tools_images_management.c srcs/ft_tools_map.c srcs/ft_tools_maps.c srcs/ft_tools_map_validity.c srcs/ft_tools_select_wall.c srcs/ft_tools_tiles.c includes/gnl/get_next_line.c includes/gnl/get_next_line_utils.c includes/gnl/get_next_line.h includes/libft/ft_atoi.c includes/libft/ft_bzero.c includes/libft/ft_calloc.c includes/libft/ft_isalnum.c includes/libft/ft_isalpha.c includes/libft/ft_isascii.c includes/libft/ft_isblank_bonus.c includes/libft/ft_isdigit.c includes/libft/ft_islower_bonus.c includes/libft/ft_isnumber_bonus.c includes/libft/ft_isprint.c includes/libft/ft_isspace_bonus.c includes/libft/ft_isupper_bonus.c includes/libft/ft_itoa.c includes/libft/ft_lstadd_back.c includes/libft/ft_lstadd_front.c includes/libft/ft_lstclear.c includes/libft/ft_lstdelone.c includes/libft/ft_lstiter.c includes/libft/ft_lstlast.c includes/libft/ft_lstmap.c includes/libft/ft_lstnew.c includes/libft/ft_lstsize.c includes/libft/ft_memccpy.c includes/libft/ft_memchr.c includes/libft/ft_memcmp.c includes/libft/ft_memcpy.c includes/libft/ft_memmove.c includes/libft/ft_memset.c includes/libft/ft_putchar_bonus.c includes/libft/ft_putchar_fd.c includes/libft/ft_putendl_bonus.c includes/libft/ft_putendl_fd.c includes/libft/ft_putnbr_bonus.c includes/libft/ft_putnbr_fd.c includes/libft/ft_putstr_bonus.c includes/libft/ft_putstr_fd.c includes/libft/ft_split.c includes/libft/ft_strcat_bonus.c includes/libft/ft_strchr.c includes/libft/ft_strcmp_bonus.c includes/libft/ft_strcpy_bonus.c includes/libft/ft_strdup.c includes/libft/ft_strjoin.c includes/libft/ft_strlcat.c includes/libft/ft_strlcpy.c includes/libft/ft_strlen.c includes/libft/ft_strmapi.c includes/libft/ft_strncat_bonus.c includes/libft/ft_strncmp.c includes/libft/ft_strncpy_bonus.c includes/libft/ft_strndup_bonus.c includes/libft/ft_strnstr.c includes/libft/ft_strrchr.c includes/libft/ft_strstr_bonus.c includes/libft/ft_strtrim.c includes/libft/ft_substr.c includes/libft/ft_tolower.c includes/libft/ft_toupper.c includes/libft/libft.h includes/ft_so_long.h includes/mlx/mlx.h includes/mlx/mlx_int.h includes/mlx/libmlx_Linux.a -L/usr/lib -lXext -lX11 -Linclude/mlx -lm -lz -D BUFFER_SIZE=32 
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
