# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 09:38:44 by awafflar          #+#    #+#              #
#    Updated: 2019/10/06 17:22:10 by awafflar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Wconversion

CC = gcc $(FLAGS)

INC = -Iinclude

SRC =	ft_printf.c 			\
		buffer.c				\
		buffer_add.c			\
		conversion.c			\
		di_tostring.c			\
		ft_dtoa.c				\
		ft_vprintf.c			\
		parse.c					\
		printf_core.c			\
		print_binary.c			\
		print_char.c			\
		print_decimal.c			\
		print_float.c			\
		print_hexa.c			\
		print_modulo.c			\
		print_n.c				\
		print_octal.c			\
		print_pointer.c			\
		print_string.c			\
		print_unsigned.c		\
		utils.c					\
		get_args_misc.c			\
		get_args_signed.c		\
		get_args_signedptr.c	\
		get_args_unsigned.c		\
		oux_tostring.c			\
		total_to_ptr.c

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
