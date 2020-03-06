# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-ber <avan-ber@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/28 13:20:50 by avan-ber       #+#    #+#                 #
#    Updated: 2020/03/06 11:39:19 by avan-ber      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cubed
FLAGS = -Wall -Werror -Wextra -g
SRCS =	cubed_functions/cub3d_utils/cub3d_utils1.c \
		cubed_functions/parcing/get_color.c \
		cubed_functions/parcing/get_resolution.c \
		cubed_functions/parcing/get_texture.c \
		cubed_functions/parcing/parse_file.c
FRAMEWORK =	-framework OpenGl\
			-framework AppKit
OFILES = $(SRCS:.c=.o)

# locations librarys
MLX_LOC		= lib/mlx
LIBFT_LOC	= lib/libft
GNL_LOC		= lib/get_next_line
VLA_LOC		= lib/vla

# librarys
LIBS			=	-L $(MLX_LOC) -lmlx\
					-L $(LIBFT_LOC) -lft\
					-L $(GNL_LOC) -lgnl \
					-L $(VLA_LOC) -lvla

# includes
INCLUDES		=	-I $(MLX_LOC) \
					-I $(LIBFT_LOC) \
					-I $(GNL_LOC) \
					-I $(VLA_LOC)
# colors
LBLUE = 	\033[38;5;14m
BLUE =		\033[38;5;12m
RED =		\033[38;5;9m
YELLOW =	\033[38;5;11m
WHITE =		\033[38;5;7m
RESET =		\x1b[0m


all: $(NAME)

%.o: %.c
	@ echo "$(LBLUE)Compiling...		$(BLUE)$<"
	@ gcc $(CFLAGS) $(INCLUDES) -I . -c $< -o $@

$(NAME): $(OFILES)
	@ echo "\n$(LBLUE)making				$(BLUE)mlx"
	@ make -C $(MLX_LOC)
	@ echo "\n$(LBLUE)copying				$(BLUE)libmlx.dylib"
	@ cp lib/mlx/libmlx.dylib .
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)making				$(BLUE)libft"
	@ make bonus -C $(LIBFT_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)making				$(BLUE)get_next_line"
	@ make bonus -C $(GNL_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)making				$(BLUE)vla"
	@ make -C $(VLA_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Compiling			$(BLUE)$(NAME)"
	@ $(CC) $(LIBS) $(FRAMEWORK) -o $(NAME) $(OFILES) $(INCLUDES) -I .
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                $(YELLOW)DONE$(RED)                ||"
	@ echo "$(RED)========================================"

clean:
	@ echo "\n$(LBLUE)Removing   		$(BLUE)mlx$(RESET)"
	@ make clean -C $(MLX_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing				$(BLUE)libft$(RESET)"
	@ make clean -C $(LIBFT_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing				$(BLUE)get_next_line$(RESET)"
	@ make clean -C $(GNL_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing				$(BLUE)vla$(RESET)"
	@ make clean -C $(VLA_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing				$(BLUE)cubed$(RESET)"
	@ rm -f $(OFILES)
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                $(YELLOW)DONE$(RED)                ||"
	@ echo "$(RED)========================================"

fclean:
	@ echo "\n$(LBLUE)Removing				$(BLUE)mlx$(RESET)"
	@ make clean -C $(MLX_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing				$(BLUE)libft$(RESET)"
	@ make fclean -C $(LIBFT_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing				$(BLUE)get_next_line$(RESET)"
	@ make fclean -C $(GNL_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing				$(BLUE)vla$(RESET)"
	@ make fclean -C $(VLA_LOC)
	@ echo "*$(YELLOW)--------------------------------------*"
	@ echo "\n$(LBLUE)Removing			$(BLUE)cubed$(RESET)"
	@ rm -f $(OFILES) $(NAME)
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                $(YELLOW)DONE$(RED)                ||"
	@ echo "$(RED)========================================$(RESET)"

re: fclean all
