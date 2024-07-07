# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 20:10:19 by nerfy             #+#    #+#              #
#    Updated: 2024/07/07 03:17:55 by nerfy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

# Répertoires sources
SRCDIR = utils
PARSINGDIR = $(SRCDIR)/parsings
HELPERSDIR = $(SRCDIR)/main_helpers
DICTIONARYDIR = $(SRCDIR)/dictionary

# Répertoires d'inclusion
INCDIR = $(SRCDIR) $(PARSINGDIR) $(HELPERSDIR) $(DICTIONARYDIR)

# Fichiers sources
SRC = main.c \
      $(DICTIONARYDIR)/dictionary.c \
      $(DICTIONARYDIR)/dictionary_helpers.c \
      $(DICTIONARYDIR)/buffer_processing1.c \
	  $(DICTIONARYDIR)/buffer_processing2.c \
      $(HELPERSDIR)/main_helpers1.c \
      $(HELPERSDIR)/main_helpers2.c \
      $(HELPERSDIR)/main_helpers3.c \
      $(SRCDIR)/string_utils.c \
      $(SRCDIR)/memory_utils.c \
      $(PARSINGDIR)/parsing.c \
      $(SRCDIR)/functions.c \
      $(PARSINGDIR)/scale_words.c \
      $(PARSINGDIR)/handling.c \
      $(PARSINGDIR)/utility.c 

# Fichiers objets
OBJ = $(SRC:.c=.o)

# Nom de l'exécutable
NAME = rush-02

# Règle par défaut
all: $(NAME)

# Lien de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation des fichiers .c en fichiers .o pour le répertoire SRCDIR
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation des fichiers .c en fichiers .o pour le répertoire PARSINGDIR
$(PARSINGDIR)/%.o: $(PARSINGDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation des fichiers .c en fichiers .o pour le répertoire HELPERSDIR
$(HELPERSDIR)/%.o: $(HELPERSDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Compilation des fichiers .c en fichiers .o pour le répertoire DICTIONARYDIR
$(DICTIONARYDIR)/%.o: $(DICTIONARYDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(foreach DIR,$(INCDIR),-I$(DIR))

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re