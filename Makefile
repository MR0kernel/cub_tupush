# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 19:59:30 by guilrodr          #+#    #+#              #
#    Updated: 2024/08/13 22:23:50 by guilrodr         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -O2 -funroll-loops
RM = rm -f
LIBFT = ./libft/libft.a

SRC =	so_long.c \
		gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		general_purpose_functions/size_and_search.c \
		general_purpose_functions/map_stock.c \
		general_purpose_functions/ft_bzero.c \
		1_given_file_tests/ends_with_ber.c \
		1_given_file_tests/is_closed.c \
		1_given_file_tests/objects_are_valid.c \
		1_given_file_tests/is_solvable.c \
		2_try_load_images/1_images_master.c \
		2_try_load_images/images_converter.c \
		2_try_load_images/init_master_structs.c \
		3_mlx_window_launch/1_window_master.c \
		3_mlx_window_launch/draw_master.c \
		3_mlx_window_launch/stop_program.c \
		3_mlx_window_launch/raycaster.c \
		4_draw_funtions/draw_by_pixel.c \
		4_draw_funtions/draw_wall.c \
		5_event_handling/1_mouvement_master.c \
		5_event_handling/key_press.c \
		error_general_hendler/error_general_hendler.c \
		error_general_hendler/free.c \
		error_general_hendler/free_images.c \
		0_Parssing/check_map.c \
		0_Parssing/check_utils.c \
		0_Parssing/color.c \
		0_Parssing/perform_parssing.c \
		0_Parssing/parse.c 0_Parssing/xpm.c

all: $(NAME)


$(NAME): $(SRC) includes/cub3d.h FORCE
	make -C mlx_linux
	$(CC) $(CFLAGS) $(SRC) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	norminette \
				general_purpose_functions \
				0_Parssing \
				1_given_file_tests \
				2_try_load_images \
				3_mlx_window_launch \
				4_draw_funtions \
				5_event_handling \
				error_general_hendler \
				so_long.c \
				includes \
				gnl \
				ft_dprintf \

$(LIBFT): FORCE
	@make --no-print-directory -C ./libft bonus

FORCE:

clean:
	make clean -C mlx_linux
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re FORCE


