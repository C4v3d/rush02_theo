/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:55 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 00:16:01 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

char	*fetch_hundred_word(t_dict_entry *dict, const char *key);
char	*fetch_tens_word(t_dict_entry *dict, const char *key);
void	print_hundred(char *word, char *hundred_word);
void	print_error(const char *message);

#endif