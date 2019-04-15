NAME	= libft.a

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

SRC = array.c
SRC += array_find.c
SRC += array_insert.c
SRC += array_size.c
SRC	+= cast_b.c
SRC += cast_csp.c
SRC += cast_d.c
SRC += cast_default.c
SRC += cast_douxb.c
SRC += cast_f.c
SRC += cast_o.c
SRC += cast_u.c
SRC += cast_x.c
SRC += cast_x_additional.c
SRC += ft_abs.c
SRC += ft_atoi.c
SRC += ft_bzero.c
SRC += ft_decimal.c
SRC += ft_double_is_negative.c
SRC += ft_dtostr.c
SRC += ft_dtostr_additional.c
SRC += ft_is_atoi_number.c
SRC += ft_isalnum.c
SRC += ft_isalpha.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isinf.c
SRC += ft_islower.c
SRC += ft_isnan.c
SRC += ft_isprint.c
SRC += ft_isspace.c
SRC += ft_isupper.c
SRC += ft_itoa.c
SRC += ft_labs.c
SRC += ft_ldecimal.c
SRC += ft_ldtostr.c
SRC += ft_llabs.c
SRC += ft_llmax.c
SRC += ft_llmin.c
SRC += ft_lmax.c
SRC += ft_lmin.c
SRC += ft_lstadd.c
SRC += ft_lstdel.c
SRC += ft_lstdelone.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_lstnew.c
SRC += ft_lstpushback.c
SRC += ft_lstsize.c
SRC += ft_max.c
SRC += ft_memalloc.c
SRC += ft_memccpy.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memcpy.c
SRC += ft_memdel.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_memswap.c
SRC += ft_min.c
SRC += ft_pcpy.c
SRC += ft_pow.c
SRC += ft_printf.c
SRC += ft_putchar.c
SRC += ft_putchar_fd.c
SRC += ft_putendl.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr.c
SRC += ft_putnbr_fd.c
SRC += ft_putstr.c
SRC += ft_putstr_fd.c
SRC += ft_skip_atoi_number.c
SRC += ft_strcat.c
SRC += ft_strchr.c
SRC += ft_strclr.c
SRC += ft_strcmp.c
SRC += ft_strcpy.c
SRC += ft_strcspn.c
SRC += ft_strdel.c
SRC += ft_strdup.c
SRC += ft_strequ.c
SRC += ft_strfilln.c
SRC += ft_striter.c
SRC += ft_striteri.c
SRC += ft_strjoin.c
SRC += ft_strlcat.c
SRC += ft_strlen.c
SRC += ft_strmap.c
SRC += ft_strmapi.c
SRC += ft_strncat.c
SRC += ft_strncmp.c
SRC += ft_strncpy.c
SRC += ft_strndup.c
SRC += ft_strnequ.c
SRC += ft_strnew.c
SRC += ft_strnstr.c
SRC += ft_strrchr.c
SRC += ft_strsplit.c
SRC += ft_strspn.c
SRC += ft_strstr.c
SRC += ft_strsub.c
SRC += ft_strtrim.c
SRC += ft_tolower.c
SRC += ft_toupper.c
SRC += ft_ulltoa_base.c
SRC += ft_ulltoa_base_size.c
SRC += get_next_line.c
SRC += other.c
SRC += parse.c
SRC += parse_specificator.c
SRC += printf_write.c

OBJ	= $(patsubst %.c, %.o, $(SRC))

INC = libft.h

all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(FLAGS) $< -c -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
