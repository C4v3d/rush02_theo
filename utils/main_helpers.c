/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:47:14 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 00:06:39 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dictionary.h"
#include "functions.h"
#include "main_helpers.h"
#include "parsing.h"
#include <stdio.h>
#include "utility.h"

#define DEFAULT_DICT "dict/en.dict"
#define BUFFER_SIZE 1024

void print_error(const char *message) {
    write(1, message, ft_strlen(message));
}

int is_valid_number(const char *str) {
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
        str++;
    if (*str == '-' || *str == '+')
        str++;
    if (*str == '\0')
        return 0;
    while (*str) {
        if (!ft_isdigit((unsigned char) *str))
            return 0;
        str++;
    }
    return 1;
}

void convert_number_to_words(t_dict_entry *dict, const char *number) {
    int len = ft_strlen(number);

    if (len == 0) {
        print_error("Error\n");
        return;
    }

    // Cas des unités et des nombres spéciaux
    if (len == 1 || (len == 2 && number[0] == '1') || (len == 2 && number[1] == '0')) {
        char *word = get_word(dict, number);
        if (word) {
            write(1, word, ft_strlen(word));
            write(1, "\n", 1);
        } else {
            print_error("Dict Error\n");
        }
        return;
    }

    // Cas des dizaines
    if (len == 2) {
        char buffer[BUFFER_SIZE];
        buffer[0] = number[0];
        buffer[1] = '0';
        buffer[2] = '\0';
        char *word = get_word(dict, buffer);
        if (word) {
            write(1, word, ft_strlen(word));
            if (number[1] != '0') {
                write(1, "-", 1);
                buffer[0] = number[1];
                buffer[1] = '\0';
                word = get_word(dict, buffer);
                if (word) {
                    write(1, word, ft_strlen(word));
                } else {
                    print_error("Dict Error\n");
                    return;
                }
            }
            write(1, "\n", 1);
        } else {
            print_error("Dict Error\n");
        }
        return;
    }

    // Cas des centaines et des grands nombres
    if (len >= 3) {
        convert_large_number_to_words(dict, number);
        return;
    }
}

int handle_args(int argc, char **argv, char *number, const char **dict_filename) {
    if (argc == 2) {
        if (!is_valid_number(argv[1])) {
            print_error("Error\n");
            return 1;
        }
        int num = ft_atoi(argv[1]);
        snprintf(number, BUFFER_SIZE, "%d", num);
    } else if (argc == 3) {
        *dict_filename = argv[1];
        if (!is_valid_number(argv[2])) {
            print_error("Error\n");
            return 1;
        }
        int num = ft_atoi(argv[2]);
        snprintf(number, BUFFER_SIZE, "%d", num);
    } else {
        print_error("Error\n");
        return 1;
    }
    return 0;
}

