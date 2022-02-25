# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 22:49:26 by lraffin           #+#    #+#              #
#    Updated: 2022/02/25 18:41:42 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

SRCS =					\
		main.c			\
		$(DISPLAY)		\
		$(DOORS)		\
		$(EVENTS)		\
		$(GEOMETRY)		\
		$(INIT)			\
		$(MINIMAP)		\
		$(OTHERS)		\
		$(PARSING)		\
		$(RAYCASTING)	\

DISPLAY =				\
		cub_load_xpm.c	\
		display_utils.c	\
		textures.c		\

DOORS =					\
		close_doors.c	\
		open_doors.c	\

EVENTS =				\
		controls.c		\
		move_player.c	\
		orient_player.c	\
		update_pos.c	\

GEOMETRY =				\
		draw.c			\

INIT =					\
		init_player.c	\
		init_struct.c	\

MINIMAP =				\
		minimap.c 		\

OTHERS =			\
		errors.c 	\
		exit.c		\
		free.c		\
		utils.c		\

PARSING =				\
		get_file.c		\
		parse_file.c	\
		check_input.c	\
		parse_walls.c 	\
		parse_walls_add_path_to_struct.c \
		parse_walls_directions.c \
		parse_img_wall.c	\
		parse_floor_ceiling.c \
		parse_floor_ceiling_check_data.c \
		parse_floor_ceiling_check_commas_digit.c \
		parse_floor_ceiling_split_color.c \
		parse_map.c \
		parse_map_check_if_map_end_of_file.c \
		parse_map_store_map.c \
		parse_map_check_first_last_letters.c \
		parse_map_check_letters.c \
		parse_map_is_valid.c \

RAYCASTING =			\
		raycasting.c	\

INC_DIR	= inc
SRC_DIR	= src
OBJ_DIR	= obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -g3 $(DEBUG)
DEBUG	= -fsanitize=address
LIBFT	= -L libft -lft
MLX		= -Lmlx -lmlx -lXext -lX11 -lm

vpath %.c $(addprefix $(SRC_DIR)/, . display doors events geometry init \
									minimap others parsing \
									parsing/floor_ceiling parsing/map \
									parsing/walls raycasting \
									)

all: libs
		@make -s $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX)
	@echo "$(_SUCCESS) cub3d"

-include $(DEPS)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "\t$(_YELLOW)compiling$(_RESET) $*.c\r\c"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(_CLEAR)"

libs:
	@make -sC libft
	@make -sC mlx

clean:
	@echo "$(_INFO) deleting object files"
	@make clean -sC libft
	@make clean -sC mlx
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(_INFO) deleting executables"
	@make fclean -sC libft
	@rm -rf $(NAME)

re: fclean all

norm:
	@echo "[$(_YELLOW)SOURCES$(_RESET)]"
	-@norminette $(SRC_DIR)
	@echo "[$(_YELLOW)INCLUDES$(_RESET)]"
	-@norminette $(INC_DIR)

push:
	git add .
	git status
	git commit -m "cub3d (make push)"
	git push

.PHONY:	all clean fclean re norm push libs

_YELLOW		= \033[38;5;184m
_GREEN		= \033[38;5;46m
_RESET		= \033[0m
_INFO		= [$(_YELLOW)INFO$(_RESET)]
_SUCCESS	= [$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		= \033[2K\c
