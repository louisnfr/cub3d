# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:18:03 by lraffin           #+#    #+#              #
#    Updated: 2022/01/25 21:53:08 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

SRCS =					\
		main.c			\
		$(GEOMETRY)		\
		$(RAYCASTING)	\
		$(DISPLAY)		\
		$(PARSING)		\
		$(EVENTS)		\
		$(EXIT)			\
		$(INIT)

RAYCASTING =			\
		precalculate.c

GEOMETRY =			\
		draw.c

EVENTS =				\
		controls.c

DISPLAY =				\
		sprites.c

PARSING =				\
		parse_map.c		\
		check_input.c	\

EXIT =					\
		free.c

INIT =					\
		init_controls.c	\
		init_sprites.c	\
		init_data.c

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

INC_DIR	= inc
SRC_DIR	= src
OBJ_DIR	= obj

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP $(DEBUG)
DEBUG	= -g3 -fsanitize=address
LIBFT	= -L libft -lft
UNAME	= $(shell uname)
ifeq ($(UNAME), Linux)
	MLX		= -Lmlx -lmlx -lXext -lX11 -lm
else ifeq ($(UNAME), Darwin)
	MLX		= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -lm
endif

vpath %.c $(addprefix $(SRC_DIR)/, . raycasting geometry display parsing sprites exit events init)


all: libs
		@make -s $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX)
	@echo "$(_SUCCESS) $(NAME)"

-include $(DEPS)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "\t$(_YELLOW)Compiling$(_RESET) $*.c\r\c"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(_CLEAR)"

libs:
	@make -sC libft
	@make -sC mlx

clean:
	@echo "$(_INFO) Deleting object files"
	@make clean -sC libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(_INFO) Deleting executables"
	@make fclean -sC libft
	@rm -f $(NAME)

re: fclean all

norm:
	@echo "$(YELLOW)SOURCES$(NOC)"
	-@norminette $(SRC_DIR)
	@echo "$(YELLOW)INCLUDES$(NOC)"
	-@norminette $(INC_DIR)

push:
	git add .
	git status
	git commit -m cub3D
	git push

.PHONY:	all clean fclean re debug norm push libs

NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		=	\033[2K\c
