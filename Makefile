# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 09:38:44 by awafflar          #+#    #+#              #
#    Updated: 2019/09/18 14:23:51 by awafflar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

INC = -Iinclude

SRC =	ft_printf.c 	\
		buffer.c		\
		ft_vprintf.c	\
		parse.c			\
		printf_core.c	\
		print_decimal.c	\
		print_modulo.c	\
		print_string.c	\
		utils.c

OBJ = $(SRC:%.c=obj/%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

obj/%.o: src/%.c
	@mkdir -p obj/
	$(CC) $(INC) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	rm -rf obj/

re: fclean all

.PHONY: all clean fclean re
