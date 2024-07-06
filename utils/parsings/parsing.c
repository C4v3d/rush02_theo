/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:15:27 by cbopp             #+#    #+#             */
/*   Updated: 2024/07/07 00:16:52 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "scale_words.h"
#include "main_helpers.h"
#include "dictionary.h"
#include "string_utils.h"
#include "handling.h"

#define BUFFER_SIZE 1024

void	handle_scale(t_dict_entry *dict, int scale)
{
	const char	*scale_word;

	if (scale > 0)
	{
		scale_word = get_scale_word(dict, scale);
		if (scale_word && ft_strlen(scale_word) > 0)
		{
			write(1, " ", 1);
			write(1, scale_word, ft_strlen(scale_word));
		}
		else
			print_error("Dict Error\n");
	}
}

void	convert_group_to_words(t_dict_entry *dict, const char *group, int scale)
{
	int	len;

	len = ft_strlen(group);
	if (len == 3 && group[0] != '0')
		handle_hundreds(dict, group);
	handle_tens(dict, group, len);
	handle_scale(dict, scale);
}

void	process_group(t_dict_entry *dict,
			const char *number, int len, int scale)
{
	char	group[4];

	ft_bzero(group, 4);
	ft_strncpy(group, number, len);
	convert_group_to_words(dict, group, scale);
}

void	convert_large_number_to_words(t_dict_entry *dict, const char *number)
{
	int		len;
	int		scale;
	int		group_len;

	len = ft_strlen(number);
	scale = (len - 1) / 3;
	while (len > 0)
	{
		if (len <= 3)
		{
			process_group(dict, number, len, scale);
			break ;
		}
		else
		{
			if (len % 3 == 0)
				group_len = 3;
			else
				group_len = len % 3;
			process_group(dict, number, group_len, scale);
			number += group_len;
			len -= group_len;
			scale--;
		}
	}
}
