# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-ber <avan-ber@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/28 13:29:47 by avan-ber      #+#    #+#                  #
#    Updated: 2020/06/26 18:37:44 by avan-ber      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libgnl
FLAGS = -Wall -Wextra -Werror
OBJECTS =	get_next_line.o \
			get_next_line_utils.o
BONUS = 	get_next_line_bonus.o \
			get_next_line_utils_bonus.o

LBLUE =		\033[38;5;14m
BLUE =		\033[38;5;12m
RED =		\033[38;5;9m
YELLOW =	\033[38;5;11m
WHITE =		\033[38;5;7m


all: $(NAME)

%.o: %.c
	@echo "$(LBLUE)Compiling...		$(BLUE)$<"
	@gcc -c -o $@ $< $(FLAGS)

$(NAME): $(OBJECTS)
	@ echo "\n$(LBLUE)making		        $(BLUE)$(NAME).a"
	@ ar rcs $(NAME).a $(OBJECTS)
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                DONE                ||"
	@ echo "$(RED)========================================"

bonus: $(BONUS)
	@echo "\n$(LBLUE)making 		   $(BLUE)$(NAME).a"
	@ar rcs $(NAME).a $(BONUS)
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                DONE                ||"
	@ echo "$(RED)========================================"

clean:
	@ echo "\n$(LBLUE)removing 		$(BLUE)objects"
	@ /bin/rm -f $(OBJECTS)
	@ /bin/rm -f $(BONUS)
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                DONE                ||"
	@ echo "$(RED)========================================"

fclean: clean
	@ echo "\n$(LBLUE)removing 		$(BLUE)$(NAME).a"
	@ /bin/rm -f 	$(NAME).a
	@ echo "\n$(LBLUE)removing          $(BLUE)$(NAME)_bonus.a"
	@ /bin/rm -f 	$(NAME)_bonus.a
	@ echo "$(RED)========================================"
	@ echo "$(RED)||                DONE                ||"
	@ echo "$(RED)========================================\n"

re: fclean all

.PHONY: all clean fclean re
