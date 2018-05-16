# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshiling <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 13:34:29 by sshiling          #+#    #+#              #
#    Updated: 2018/03/19 13:34:38 by sshiling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sshiling.filler
FLAGS = -Wall -Wextra -Werror

SRC_NAME = main.c map_creator.c find_the_best_solution.c create_results.c \
	free_functions.c create_functions.c create_digital_map.c create_cords.c \
	fill_map_with_distance.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = -Iincludes/ -I$(LIB_DIR)includes/

LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR) --silent
	@echo "##### Lib created #####"
	gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft
	@echo "##### Compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	@echo "##### Linking" [ $@ ] " #####"
	gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re
