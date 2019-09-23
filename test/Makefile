NAME = ft_printf

FLAG = -Wall -Werror -Wextra -g

SRC =	main.c\

OBJ = $(SRC:%.c=obj/%.o)

INC  = -I../include/

LIB = -L../ -lftprintf

CC  = gcc $(FLAG)

$(NAME):  $(OBJ)
	$(CC) $^ $(LIB) -o $@

all: $(NAME)

obj/%.o: %.c
	@mkdir -p obj/
	$(CC) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf obj

re: fclean all

.PHONY: all re clean fclean
