cmake_minimum_required(VERSION 3.13)
project(fdf C)

set(CMAKE_C_STANDARD 11)

add_executable(fdf main.c inc/array_point.h inc/array2_point.h src/array_point.c src/array2_point.c inc/point.h inc/matrix4.h src/matrix4.c inc/color.h src/point.c libft/ft_sign.c libft/ft_atox.c libft/is_atox_digit.c libft/skip_atox_number.c inc/options.h src/options.c inc/data.h inc/keyboard.h inc/draw.h src/draw.c src/data.c inc/draw_context.h src/keyboard.c src/draw_context.c inc/parse.h src/parse.c inc/utils.h src/utils.c)

target_link_libraries(fdf /Users/myaremen/CLionProjects/fdf/libft/libft.a)

target_link_libraries(fdf /Users/myaremen/CLionProjects/fdf/minilibx_macos/libmlx.a)

target_include_directories(fdf PUBLIC libft/ inc/ )#minilibx_macos/)

target_link_libraries(fdf -lmlx "-framework OpenGL" "-framework AppKit")

add_compile_options(-Wall -Wextra -pedantic -Werror)