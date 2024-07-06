/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:11:28 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/06 22:11:29 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPERS_H
#define MAIN_HELPERS_H

#include "functions.h"
#include "dictionary.h"

void	print_error(const char *message);
int	is_valid_number(const char *str);
void	convert_number_to_words(t_dict_entry *dict, const char *number);
int	handle_args(int argc, char **argv, char *number, const char **dict_filename);

#endif

