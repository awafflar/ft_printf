# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 09:38:44 by awafflar          #+#    #+#              #
#    Updated: 2019/09/18 09:38:54 by awafflar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

SRC =	ft_printf.c

OBJ = $(SRC:%.c=obj/%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

obj/%.o: %.c
	@mkdir -p obj/
	$(CC) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
