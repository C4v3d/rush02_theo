/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_processing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:31:00 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:25:05 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_PROCESSING_H
# define BUFFER_PROCESSING_H

# include "dictionary.h"
# include "dictionary_helpers.h"
# include "common_dictionary.h"

int				allocate_line_buffer(t_line_info *line_info);
int				process_newline(t_line_info *line_info, char *start,
					char *newline, t_dict_entry **head);
int				handle_line_remainder(t_line_info *line_info,
					char *start, t_dict_entry **head);
int				process_buffer_part(t_line_info *line_info,
					char *start, t_dict_entry **head);
int				process_buffer(char *buffer,
					size_t bytes_read, t_line_info *line_info,
					t_dict_entry **head);
t_dict_entry	*process_file(int fd, t_line_info *line_info);
t_dict_entry	*read_lines_from_file(int fd);

#endif