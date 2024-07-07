/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_processing1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:24 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:20:45 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_processing.h"
#include "common_dictionary.h"

int	allocate_line_buffer(t_line_info *line_info)
{
	char	*new_line;

	line_info->capacity *= 2;
	new_line = malloc(line_info->capacity);
	if (!new_line)
	{
		write(1, "Memory Error\n", 13);
		free(line_info->line);
		return (0);
	}
	ft_strcpy(new_line, line_info->line);
	free(line_info->line);
	line_info->line = new_line;
	return (1);
}

int	process_newline(t_line_info *line_info, char *start,
		char *newline, t_dict_entry **head)
{
	if (!line_info || !start || !newline || !head)
	{
		return (0);
	}
	newline[0] = '\0';
	ft_strcpy(line_info->line + line_info->len, start);
	line_info->len += (newline - start);
	line_info->line[line_info->len] = '\0';
	process_line(line_info->line, head);
	line_info->len = 0;
	return (1);
}

int	handle_line_remainder(t_line_info *line_info,
		char *start, t_dict_entry **head)
{
	if (!line_info || !start || !head)
	{
		return (0);
	}
	if (*start != '\0')
	{
		if (line_info->len + ft_strlen(start) + 1 > line_info->capacity)
		{
			if (!allocate_line_buffer(line_info))
			{
				free_dictionary(*head);
				return (0);
			}
		}
		ft_strcpy(line_info->line + line_info->len, start);
		line_info->len += ft_strlen(start);
	}
	return (1);
}
