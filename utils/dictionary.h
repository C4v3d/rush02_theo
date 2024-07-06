/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:07:10 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/06 22:01:52 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct s_dict_entry {
    char *number;
    char *word;
    struct s_dict_entry *next;
} t_dict_entry;

t_dict_entry *load_dictionary(const char *filename);
char *get_word(t_dict_entry *dict, const char *number);
void free_dictionary(t_dict_entry *dict);

#endif
