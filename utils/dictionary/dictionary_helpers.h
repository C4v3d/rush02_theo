/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_helpers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:50 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:26:52 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_HELPERS_H
# define DICTIONARY_HELPERS_H

# include "dictionary.h"

t_dict_entry	*create_entry(const char *number, const char *word);
void			add_entry(t_dict_entry **head, t_dict_entry *new_entry);
void			process_line(char *line, t_dict_entry **head);

#endif