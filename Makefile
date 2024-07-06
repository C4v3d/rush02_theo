CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRC = main.c dictionary.c
OBJ = $(SRC:.c=.o)
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re