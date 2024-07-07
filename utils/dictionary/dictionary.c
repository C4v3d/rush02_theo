/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:29:36 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:21:03 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "dictionary_helpers.h"
#include "buffer_processing.h"

t_dict_entry	*load_dictionary(const char *filename)
{
	int				fd;
	t_dict_entry	*head;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	head = read_lines_from_file(fd);
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
	t_dict_entry	*temp;

	while (dict)
	{
		temp = dict;
		dict = dict->next;
		free(temp->number);
		free(temp->word);
		free(temp);
	}
}
