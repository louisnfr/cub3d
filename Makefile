SRCS =		main.c \
			srcs/free/free_1.c \
			srcs/utils/utils_1.c \
			srcs/utils/ft_lstadd_back.c \
			srcs/utils/ft_lstdelone.c \
			srcs/utils/ft_lstlast.c \
			srcs/utils/ft_lstnew.c \
			srcs/utils/ft_memset.c \
			srcs/utils/ft_strlen.c \
			srcs/parsing/parsing_map.c \
			srcs/utils/get_next_line.c \
			srcs/utils/ft_calloc.c \
			srcs/utils/ft_lstclear.c \
			srcs/affichage_map/affichage_map.c \
			srcs/affichage_map/affichage_game.c \
			srcs/sprites/creation_sprites_1.c \

OBJS         = ${SRCS:.c=.o}

UNAME        := $(shell uname)

PATH_MLX    = mlx
CC             = gcc -g
CFLAGS        = -Wall -Wextra -Werror
RM            = rm -f
NAME        = cube_3d
FLAGS        = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

all:         ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):     $(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

bonus:		all

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}

fclean:     clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re:         fclean all

.PHONY:		bonus all clean fclean re
