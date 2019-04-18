NAME = fdf

src =

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra main.c src/*.c -Ilibft -Iinc -Llibft -lft -lmlx -framework OpenGL -framework AppKit -o fdf

clean:


.PHONY: all clean fclean re