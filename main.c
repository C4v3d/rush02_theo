#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define DEFAULT_DICT "en.dict"
#define BUFFER_SIZE 1024

void print_error(const char *message) {
    write(1, message, strlen(message));
}

int is_valid_number(const char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}

void convert_number_to_words(t_dict_entry *dict, const char *number) {
    char *word = get_word(dict, number);
    if (word) {
        write(1, word, strlen(word));
        write(1, "\n", 1);
    } else {
        print_error("Dict Error\n");
    }
}

int main(int argc, char **argv) {
    const char *dict_filename = DEFAULT_DICT;
    char number[BUFFER_SIZE] = {0};

    if (argc == 2) {
        if (!is_valid_number(argv[1])) {
            print_error("Error\n");
            return 1;
        }
        strncpy(number, argv[1], BUFFER_SIZE - 1);
    } else if (argc == 3) {
        dict_filename = argv[1];
        if (!is_valid_number(argv[2])) {
            print_error("Error\n");
            return 1;
        }
        strncpy(number, argv[2], BUFFER_SIZE - 1);
    } else {
        print_error("Error\n");
        return 1;
    }

    t_dict_entry *dict = load_dictionary(dict_filename);
    if (!dict) {
        print_error("Dict Error\n");
        return 1;
    }

    convert_number_to_words(dict, number);

    free_dictionary(dict);
    return 0;
}
