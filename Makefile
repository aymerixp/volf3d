# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/10 12:21:12 by aratinau          #+#    #+#              #
#    Updated: 2016/02/03 12:31:36 by aratinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

SRC = wolf.c \
	  print_cam.c \
	  draw_function.c \
	  event_mlx.c

#ARGS = ../../42_projects/fdf/new_start/maps

OBJ_PATH = ./obj/

OBJ2 = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3
OBJ = $(addprefix $(OBJ_PATH),$(OBJ2))

#ecole
$(NAME): $(OBJ)
	make -C includes/libft/
	$(CC) $(CFLAGS) includes/libft/libft.a -o $(NAME) $(OBJ) \
	-lmlx -framework OpenGL -framework AppKit

#maison
#$(NAME): $(OBJ)
#	make -C ../libraire/
#	make -C ../../minilibx_test_ok/includes/minilibx/
#	$(CC) $(CFLAGS) ../libraire/libft.a \
	../../minilibx_test_ok/includes/minilibx/libmlx.a -o $(NAME) $(OBJ) \
	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)