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
		get_file.c		\
		parse_file.c	\
		check_input.c	\
		parse_walls.c 	\
		parse_walls_add_path_to_struct.c \
		parse_walls_directions.c \
		parse_img_wall.c	\
		ft_split_charset.c	\
		ft_is_digit_comma.c \
		ft_strlen_doublestr.c \
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
		errors.c \

EXIT =					\
		free.c

INIT =					\
		init_controls.c	\
		init_sprites.c	\
		init_data.c \
		init_struct.c \


OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

INC_DIR	= inc
SRC_DIR	= src
OBJ_DIR	= obj

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP #$(DEBUG)
DEBUG	= -g3 -fsanitize=address
LIBFT	= -L libft -lft
UNAME	= $(shell uname)
ifeq ($(UNAME), Linux)
MLX		= -Lmlx -lmlx -lXext -lX11 -lm
else ifeq ($(UNAME), Darwin)
	MLX		= -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -lm
endif

vpath %.c $(addprefix $(SRC_DIR)/, . raycasting geometry display parsing sprites exit events init parsing/walls parsing/utils parsing/map parsing/floor_ceiling)

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
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(_INFO) deleting executables"
	@make fclean -sC libft
	@rm -f $(NAME)

re: fclean all

norm:
	@echo "[$(YELLOW)SOURCES$(NOC)]"
	-@norminette $(SRC_DIR)
	@echo "[$(YELLOW)INCLUDES$(NOC)]"
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

_YELLOW		= \033[38;5;184m
_GREEN		= \033[38;5;46m
_RESET		= \033[0m
_INFO		= [$(_YELLOW)INFO$(_RESET)]
_SUCCESS	= [$(_GREEN)SUCCESS$(_RESET)]
_CLEAR		= \033[2K\c