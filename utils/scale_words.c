/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:56:39 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/06 22:05:53 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "scale_words.h"
#include "main_helpers.h"
#define BUFFER_SIZE 1024
// Cette fonction retourne le mot correspondant à l'échelle en utilisant le dictionnaire
const char *get_scale_word(t_dict_entry *dict, int scale) {
    char buffer[BUFFER_SIZE];

    // Construire la clé pour l'échelle
    switch (scale) {
        case 1:
            strcpy(buffer, "1000");
            break;
        case 2:
            strcpy(buffer, "1000000");
            break;
        case 3:
            strcpy(buffer, "1000000000");
            break;
        case 4:
            strcpy(buffer, "1000000000000");
            break;
        case 5:
            strcpy(buffer, "1000000000000000");
            break;
        case 6:
            strcpy(buffer, "1000000000000000000");
            break;
        case 7:
            strcpy(buffer, "1000000000000000000000");
            break;
        case 8:
            strcpy(buffer, "1000000000000000000000000");
            break;
        case 9:
            strcpy(buffer, "1000000000000000000000000000");
            break;
        case 10:
            strcpy(buffer, "1000000000000000000000000000000");
            break;
        case 11:
            strcpy(buffer, "1000000000000000000000000000000000");
            break;
        case 12:
            strcpy(buffer, "1000000000000000000000000000000000000");
            break;
        default:
            return "";
    }

    // Trouver le mot correspondant dans le dictionnaire
    char *word = get_word(dict, buffer);
    if (word) {
        return word;
    } else {
        return "";
    }
}
