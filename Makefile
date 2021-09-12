# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/09/12 16:34:58 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

SRCS=$(addprefix ${FOLDER}/, ft_so_long.c)

OBJS=$(SRCS:.c=.o)

INCLUDES=includes
FOLDER=srcs

NAME_LIBFT=libft
LIBFT=$(addprefix ${INCLUDES}/, libft)
MLX=mlx

CC=gcc -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
CMLXFLAGS_C=-Imlx -c
CMLXFLAGS=-Lmlx -lmlx -framework OpenGL -framework AppKit
RM=rm -f

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) $(CMLXFLAGS) -o $@ $^ $(LIBFT)/libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) $(CMLXFLAGS_C) -o $@ $< -I $(INCLUDES)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

re_bonus: fclean bonus
