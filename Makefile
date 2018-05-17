#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarev <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/05 17:02:57 by skarev            #+#    #+#              #
#    Updated: 2018/05/09 18:30:10 by ptatarsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = main.c make_a_struct.c read.c validator_3000.c zero_position.c \
						map_func.c solution.c
LIB = ./libft/libft.a

all: $(NAME)

$(NAME): $(FILES)
		@make -C libft
		@gcc $(FLAGS) -o $(NAME) $(FILES) $(LIB)

clean:
		@make -C libft clean

fclean: clean
		@make -C libft fclean
		@/bin/rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
