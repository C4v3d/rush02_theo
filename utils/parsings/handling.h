/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:17:15 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 00:17:15 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLING_H
# define HANDLING_H

void	handle_hundreds(t_dict_entry *dict, const char *group);
void	handle_tens(t_dict_entry *dict, const char *group, int len);
void	print_tens_and_units(t_dict_entry *dict,
			char *word, const char *group, int len);

#endif