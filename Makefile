# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 09:38:44 by awafflar          #+#    #+#              #
#    Updated: 2019/10/01 15:29:56 by awafflar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

INC = -Iinclude

SRC =	ft_printf.c 			\
		buffer.c				\
		buffer_add.c			\
		conversion.c			\
		di_tostring.c			\
		ft_vprintf.c			\
		parse.c					\
		printf_core.c			\
		print_decimal.c			\
		print_hexa.c			\
		print_modulo.c			\
		print_string.c			\
		utils.c					\
		get_args_misc.c			\
		get_args_signed.c		\
		get_args_signedptr.c	\
		get_args_unsigned.c		\
		oux_tostring.c

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
