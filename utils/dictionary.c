/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:07:04 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/06 21:15:05 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "dictionary.h"
#include "functions.h"

#define BUFFER_SIZE 1024

static char	*trim(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r'))
		end--;
	end[1] = '\0';
	return (str);
}

static t_dict_entry	*create_entry(const char *number, const char *word)
{
	t_dict_entry	*entry;

	entry = malloc(sizeof(t_dict_entry));
	if (!entry)
		return (NULL);
	entry->number = ft_strdup(trim((char *)number));
	entry->word = ft_strdup(trim((char *)word));
	entry->next = NULL;
	return (entry);
}

static void	add_entry(t_dict_entry **head, t_dict_entry *new_entry)
{
	if (*head == NULL)
	{
		*head = new_entry;
	}
	else
	{
		t_dict_entry	*current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_entry;
	}
}

t_dict_entry	*load_dictionary(const char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	t_dict_entry	*head = NULL;
	char	*line = NULL;
	size_t	len = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		char	*start = buffer;
		char	*newline = NULL;
		while ((newline = ft_strchr(start, '\n')) != NULL)
		{
			*newline = '\0';
			if (line == NULL)
			{
				line = ft_strdup(start);
			}
			else
			{
				line = realloc(line, len + (newline - start) + 1);
				ft_strcat(line, start);
			}
			len = 0;
			char	*colon = ft_strchr(line, ':');
			if (colon)
			{
				*colon = '\0';
				t_dict_entry	*entry = create_entry(line, colon + 1);
				if (entry)
					add_entry(&head, entry);
			}
			free(line);
			line = NULL;
			start = newline + 1;
		}
		if (*start != '\0')
		{
			len = ft_strlen(start);
			line = malloc(len + 1);
			ft_strcpy(line, start);
		}
	}
	if (line)
		free(line);
	close(fd);
	return (head);
}

char	*get_word(t_dict_entry *dict, const char *number)
{
	while (dict)
	{
		if (ft_strcmp(dict->number, number) == 0)
			return (dict->word);
		dict = dict->next;
	}
	return (NULL);
}

void	free_dictionary(t_dict_entry *dict)
{
	while (dict)
	{
		t_dict_entry	*temp = dict;
		dict = dict->next;
		free(temp->number);
		free(temp->word);
		free(temp);
	}
}
