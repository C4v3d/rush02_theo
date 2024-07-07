/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:34 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 02:46:04 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPERS2_H
# define MAIN_HELPERS2_H

# include "main_helpers_common.h"
# include <unistd.h>
# include "../dictionary/dictionary.h"
# include "../functions.h"
# include "../parsings/parsing.h"
# include "../parsings/utility.h"

void	handle_non_zero_second_digit(t_dict_entry *dict, const char *number,
			char *buffer);
void	handle_word_output(char *word);
void	handle_buffer_error(void);
void	handle_two_digits(t_dict_entry *dict, const char *number);

#endif