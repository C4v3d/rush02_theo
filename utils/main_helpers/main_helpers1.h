/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:14 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 02:45:43 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPERS1_H
# define MAIN_HELPERS1_H

# include "main_helpers_common.h"
# include <unistd.h>
# include "../dictionary/dictionary.h"
# include "../functions.h"
# include "../parsings/parsing.h"
# include "../parsings/utility.h"

void	print_error(const char *message);
int		is_valid_number(const char *str);
void	handle_empty_number(void);
void	handle_single_digit(t_dict_entry *dict, const char *number);

#endif