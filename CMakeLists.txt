cmake_minimum_required(VERSION 3.13)
project(fdf C)

set(CMAKE_C_STANDARD 11)

add_executable(fdf main.c inc/array_point.h inc/array2_point.h src/array_point.c src/array2_point.c inc/point.h inc/matrix4.h src/matrix4.c inc/color.h)

target_link_libraries(fdf /Users/myaremen/CLionProjects/fdf/libft/libft.a)

#target_link_libraries(fdf /Users/myaremen/CLionProjects/fdf/minilibx_macos/libmlx.a)

target_include_directories(fdf PUBLIC libft/ inc/ )#minilibx_macos/)

target_link_libraries(fdf -lmlx "-framework OpenGL" "-framework AppKit")