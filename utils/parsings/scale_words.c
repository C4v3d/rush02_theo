/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:56:39 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 01:52:49 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scale_words.h"
#include "main_helpers1.h"
#include "main_helpers2.h"
#include "main_helpers3.h"
#include "string_utils.h"

#define BUFFER_SIZE 1024

static const char	*get_scale_string(int scale)
{
	const char	*scale_strings[] = {
		"", "1000", "1000000", "1000000000", "1000000000000",
		"1000000000000000", "1000000000000000000",
		"1000000000000000000000", "1000000000000000000000000",
		"1000000000000000000000000000",
		"1000000000000000000000000000000",
		"1000000000000000000000000000000000",
		"1000000000000000000000000000000000000"
	};

	if (scale < 0
		|| scale >= (int)(sizeof(scale_strings) / sizeof(scale_strings[0])))
		return ("");
	return (scale_strings[scale]);
}

const char	*get_scale_word(t_dict_entry *dict, int scale)
{
	char		buffer[BUFFER_SIZE];
	const char	*scale_str;
	char		*word;

	scale_str = get_scale_string(scale);
	ft_strcpy(buffer, scale_str);
	word = get_word(dict, buffer);
	if (word)
		return (word);
	else
		return ("");
}
