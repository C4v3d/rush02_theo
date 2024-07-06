# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 20:10:19 by nerfy             #+#    #+#              #
#    Updated: 2024/07/06 21:59:44 by nerfy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRCDIR = utils
INCDIR = $(SRCDIR)
SRC = main.c $(SRCDIR)/dictionary.c $(SRCDIR)/main_helpers.c $(SRCDIR)/string_utils.c $(SRCDIR)/memory_utils.c $(SRCDIR)/parsing.c $(SRCDIR)/functions.c $(SRCDIR)/scale_words.c
OBJ = $(SRC:.c=.o)
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCDIR)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re