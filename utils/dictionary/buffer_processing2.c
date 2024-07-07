/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_processing2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 03:15:14 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:26:01 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_processing.h"
#include "common_dictionary.h"

int	process_buffer_part(t_line_info *line_info,
		char *start, t_dict_entry **head)
{
	char	*newline;

	newline = ft_strchr(start, '\n');
	while (newline != NULL)
	{
		if (line_info->len + (newline - start) + 1 > line_info->capacity)
		{
			if (!allocate_line_buffer(line_info))
			{
				free_dictionary(*head);
				return (0);
			}
		}
		if (!process_newline(line_info, start, newline, head))
		{
			free_dictionary(*head);
			return (0);
		}
		start = newline + 1;
		newline = ft_strchr(start, '\n');
	}
	return (handle_line_remainder(line_info, start, head));
}

int	process_buffer(char *buffer,
		size_t bytes_read, t_line_info *line_info, t_dict_entry **head)
{
	if (!buffer || !line_info || !head)
	{
		return (0);
	}
	buffer[bytes_read] = '\0';
	return (process_buffer_part(line_info, buffer, head));
}

t_dict_entry	*process_file(int fd, t_line_info *line_info)
{
	char			buffer[BUFFER_SIZE + 1];
	int				bytes_read;
	t_dict_entry	*head;

	if (!line_info)
	{
		return (NULL);
	}
	head = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!process_buffer(buffer, bytes_read, line_info, &head))
		{
			free(line_info->line);
			free_dictionary(head);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (head);
}

t_dict_entry	*read_lines_from_file(int fd)
{
	t_dict_entry	*head;
	t_line_info		line_info;

	line_info.line = NULL;
	line_info.len = 0;
	line_info.capacity = BUFFER_SIZE;
	line_info.line = malloc(line_info.capacity);
	if (!line_info.line)
	{
		write(1, "Memory Error\n", 13);
		return (NULL);
	}
	head = process_file(fd, &line_info);
	free(line_info.line);
	return (head);
}
