# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 22:49:26 by lraffin           #+#    #+#              #
#    Updated: 2022/02/25 17:48:15 by lraffin          ###   ########.fr        #
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
		$(INIT)			\
		$(BONUS)		\

RAYCASTING =			\
		raycasting.c	\

GEOMETRY =				\
		draw.c

EVENTS =				\
		controls.c		\
		move_player.c	\
		orient_player.c	\
		update_pos.c	\

DISPLAY =				\
		cub_load_xpm.c	\
		utils.c			\
		textures.c		\

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

EXIT =				\
		errors.c 	\
		free.c		\
		exit.c		\

INIT =					\
		init_player.c	\
		init_struct.c	\

BONUS =					\
		mini_map.c 		\
		map_utils.c		\
		open_doors.c	\
		utils_bonus.c 	\
		close_doors.c	\

INC_DIR	= inc
SRC_DIR	= src
OBJ_DIR	= obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -g3 #$(DEBUG)
DEBUG	= -fsanitize=address
LIBFT	= -L libft -lft
MLX		= -Lmlx -lmlx -lXext -lX11 -lm

vpath %.c $(addprefix $(SRC_DIR)/, . raycasting geometry	\
									display parsing bonus	\
									exit events init	\
									parsing/walls	\
									parsing/map parsing/floor_ceiling	\
									ceiling_floor doors	\
									draw hud utils	\
									mini_map	\
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
