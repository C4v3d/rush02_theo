# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 20:10:19 by nerfy             #+#    #+#              #
#    Updated: 2024/07/07 00:14:49 by nerfy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRCDIR = utils
PARSINGDIR = $(SRCDIR)/parsings
INCDIR = $(SRCDIR) $(PARSINGDIR)
SRC = main.c $(SRCDIR)/dictionary.c $(SRCDIR)/main_helpers.c $(SRCDIR)/string_utils.c $(SRCDIR)/memory_utils.c $(PARSINGDIR)/parsing.c $(SRCDIR)/functions.c $(SRCDIR)/scale_words.c $(PARSINGDIR)/handling.c $(PARSINGDIR)/utility.c
OBJ = $(SRC:.c=.o)
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(SRCDIR) -I$(PARSINGDIR)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(SRCDIR) -I$(PARSINGDIR)

$(PARSINGDIR)/%.o: $(PARSINGDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(SRCDIR) -I$(PARSINGDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(SRCDIR) -I$(PARSINGDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re