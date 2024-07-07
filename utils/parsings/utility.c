/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:58:48 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 00:16:13 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dictionary.h"
#include "string_utils.h"
#include "utility.h"

char	*fetch_hundred_word(t_dict_entry *dict, const char *key)
{
	char	*word;

	word = get_word(dict, key);
	if (!word)
	{
		print_error("Dict Error\n");
		return (NULL);
	}
	return (word);
}

char	*fetch_tens_word(t_dict_entry *dict, const char *key)
{
	char	*word;

	word = get_word(dict, key);
	if (!word)
	{
		print_error("Dict Error\n");
		return (NULL);
	}
	return (word);
}

void	print_hundred(char *word, char *hundred_word)
{
	write(1, word, ft_strlen(word));
	write(1, " ", 1);
	write(1, hundred_word, ft_strlen(hundred_word));
	write(1, " ", 1);
}
