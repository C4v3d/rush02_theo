/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:37:15 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 01:50:57 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helpers2.h"

void	handle_non_zero_second_digit(t_dict_entry *dict, const char *number,
			char *buffer)
{
	char	*word;

	write(1, "-", 1);
	buffer[0] = number[1];
	buffer[1] = '\0';
	word = get_word(dict, buffer);
	if (word)
	{
		write(1, word, ft_strlen(word));
	}
	else
	{
		print_error("Dict Error\n");
	}
}

void	handle_word_output(char *word)
{
	write(1, word, ft_strlen(word));
	write(1, "\n", 1);
}

void	handle_buffer_error(void)
{
	print_error("Dict Error\n");
}

void	handle_two_digits(t_dict_entry *dict, const char *number)
{
	char	buffer[BUFFER_SIZE];
	char	*word;

	buffer[0] = number[0];
	buffer[1] = '0';
	buffer[2] = '\0';
	word = get_word(dict, buffer);
	if (word)
	{
		handle_word_output(word);
		if (number[1] != '0')
		{
			handle_non_zero_second_digit(dict, number, buffer);
		}
		else
		{
			write(1, "\n", 1);
		}
	}
	else
	{
		handle_buffer_error();
	}
}
