# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:18:03 by lraffin           #+#    #+#              #
#    Updated: 2022/01/18 15:55:27 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

SRCS =				\
		main.c		\
		$(DISPLAY)	\
		$(PARSING)	\
		$(EVENTS)	\
		$(EXIT)		\
		$(INIT)

EVENTS =		\
		controls.c

DISPLAY =					\
		draw_line.c	\
		start.c	\
		sprites.c

PARSING =				\
		parse_map.c


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
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -g3 $(DEBUG)
DEBUG	= -fsanitize=address
LIBFT	= -L libft -lft
MLX		= -Lmlx -lmlx -lXext -lX11 -lm

vpath %.c $(addprefix $(SRC_DIR)/, . display parsing sprites exit events init)

all: libs
		@make -s $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX)
	@echo "$(GREEN)$@$(NOC)"

-include $(DEPS)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(BLUE)clang $(NOC)$(notdir $@)"

libs:
		@make -sC libft
		@make -sC mlx

clean:
	@echo "$(RED)clean$(NOC)"
	@make clean -sC libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
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
