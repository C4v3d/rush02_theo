/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:08 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:12:39 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary_helpers.h"

t_dict_entry	*create_entry(const char *number, const char *word)
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

void	add_entry(t_dict_entry **head, t_dict_entry *new_entry)
{
	t_dict_entry	*current;

	if (*head == NULL)
	{
		*head = new_entry;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_entry;
	}
}

void	process_line(char *line, t_dict_entry **head)
{
	char			*colon;
	t_dict_entry	*entry;

	colon = ft_strchr(line, ':');
	if (colon)
	{
		*colon = '\0';
		entry = create_entry(line, colon + 1);
		if (entry)
			add_entry(head, entry);
		else
		{
			free(line);
			free_dictionary(*head);
			write(1, "Dict Error\n", 11);
		}
	}
}
