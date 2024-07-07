/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers3.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:46 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 02:46:15 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPERS3_H
# define MAIN_HELPERS3_H

# include "main_helpers_common.h"
# include <unistd.h>
# include "../dictionary/dictionary.h"
# include "../functions.h"
# include "../parsings/parsing.h"
# include "../parsings/utility.h"

void	convert_number_to_words(t_dict_entry *dict, const char *number);
int		handle_two_args(char *arg, char *number);
int		handle_three_args(char *arg1,
			char *arg2, const char **dict_filename, char *number);
int		handle_args(int argc, char **argv,
			char *number, const char **dict_filename);

#endif