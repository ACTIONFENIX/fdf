NAME = fdf

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra main.c src/*.c -Ilibft -Iinc -Llibft -lft -lmlx -framework OpenGL -framework AppKit -o fdf