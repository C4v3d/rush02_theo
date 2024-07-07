/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:22:05 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/06 23:25:13 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	convert_number_to_words(t_dict_entry *dict, const char *number);
void	convert_group_to_words(t_dict_entry *dict,
			const char *group, int scale);
void	convert_large_number_to_words(t_dict_entry *dict, const char *number);

#endif
