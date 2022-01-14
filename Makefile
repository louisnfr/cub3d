# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:18:03 by lraffin           #+#    #+#              #
#    Updated: 2022/01/14 17:59:50 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

SRCS =				\
		main.c		\
		$(DISPLAY)	\
		$(PARSING)	\
		$(SPRITES)	\
		$(FREE)		\
		$(UTILS)

DISPLAY =					\
		affichage_game.c	\
		affichage_map.c

PARSING =				\
		parsing_map.c

SPRITES =				\
		creation_sprites_1.c

FREE =					\
		free_1.c

UTILS =					\
		ft_calloc.c			\
		ft_lstadd_back.c	\
		ft_lstclear.c		\
		ft_lstdelone.c	\
		ft_lstlast.c	\
		ft_lstnew.c	\
		ft_memset.c	\
		ft_strlen.c	\
		get_next_line.c	\
		utils_1.c

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

INC_DIR	= inc
SRC_DIR	= src
OBJ_DIR	= obj

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -g3 #$(DEBUG)
DEBUG	= -g3 -fsanitize=address
LIBFT	= -L libft -lft
MLX		= -Lmlx -lmlx -lXext -lX11 -lm

vpath %.c $(addprefix $(SRC_DIR)/, . display parsing sprites free utils)

all: libs
		@make -s $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)
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
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
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
