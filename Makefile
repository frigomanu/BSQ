# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momil-vo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 13:00:51 by momil-vo          #+#    #+#              #
#    Updated: 2022/11/23 04:39:00 by momil-vo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

FLAGS = -Wextra -Werror -Wall

SRC = auxiliar1.c auxiliar2.c auxiliar3.c manage_input.c manage_input_2.c \
	  main.c mapcheker.c maproutines.c read.c solve.c symbols.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ):
	@gcc $(FLAGS) $(SRC) -c

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re exec run
