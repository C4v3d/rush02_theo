/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:15:27 by cbopp             #+#    #+#             */
/*   Updated: 2024/07/06 22:05:27 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "scale_words.h"
#include "main_helpers.h"
#include "dictionary.h"
#define BUFFER_SIZE 1024

void convert_group_to_words(t_dict_entry *dict, const char *group, int scale) {
    int len = strlen(group);

    // Vérification des centaines
    if (len == 3 && group[0] != '0') {
        char buffer[BUFFER_SIZE];
        buffer[0] = group[0];
        buffer[1] = '\0';
        char *word = get_word(dict, buffer);
        if (word) {
            write(1, word, strlen(word));
            write(1, " ", 1);
            char *hundred_word = get_word(dict, "100");
            if (hundred_word) {
                write(1, hundred_word, strlen(hundred_word));
                write(1, " ", 1);
            } else {
                print_error("Dict Error\n");
                return;
            }
        } else {
            print_error("Dict Error\n");
            return;
        }
    }

    // Vérification des dizaines et unités
    if (len >= 2 && group[len-2] != '0') {
        char buffer[BUFFER_SIZE];
        buffer[0] = group[len-2];
        buffer[1] = '0';
        buffer[2] = '\0';
        char *word = get_word(dict, buffer);
        if (word) {
            write(1, word, strlen(word));
            if (group[len-1] != '0') {
                write(1, "-", 1);
                buffer[0] = group[len-1];
                buffer[1] = '\0';
                word = get_word(dict, buffer);
                if (word) {
                    write(1, word, strlen(word));
                } else {
                    print_error("Dict Error\n");
                    return;
                }
            }
        } else {
            print_error("Dict Error\n");
            return;
        }
    } else if (len >= 1 && group[len-1] != '0') {
        char buffer[BUFFER_SIZE];
        buffer[0] = group[len-1];
        buffer[1] = '\0';
        char *word = get_word(dict, buffer);
        if (word) {
            write(1, word, strlen(word));
        } else {
            print_error("Dict Error\n");
            return;
        }
    }

    // Vérification des échelles (mille, million, etc.)
    if (scale > 0) {
        const char *scale_word = get_scale_word(dict, scale);
        if (scale_word && strlen(scale_word) > 0) {
            char buffer[BUFFER_SIZE];
            snprintf(buffer, sizeof(buffer), " %s", scale_word);
            write(1, buffer, strlen(buffer));
        } else {
            print_error("Dict Error\n");
            return;
        }
    }
}

void convert_large_number_to_words(t_dict_entry *dict, const char *number) {
    int len = ft_strlen(number);
    int scale = (len - 1) / 3;
    char group[4];

    while (len > 0) {
        if (len <= 3) {
            ft_bzero(group, 4);
            ft_strncpy(group, number, len);
            convert_group_to_words(dict, group, scale);
            break;
        } else {
            int group_len = len % 3 == 0 ? 3 : len % 3;
            ft_bzero(group, 4);
            ft_strncpy(group, number, group_len);
            convert_group_to_words(dict, group, scale);
            number += group_len;
            len -= group_len;
            scale--;
        }
    }
}
