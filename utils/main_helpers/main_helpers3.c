/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:37:26 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 01:50:30 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helpers3.h"
#include "main_helpers1.h"
#include "main_helpers2.h"

void	convert_number_to_words(t_dict_entry *dict, const char *number)
{
	int	len;

	len = ft_strlen(number);
	if (len == 0)
	{
		handle_empty_number();
		return ;
	}
	if (len == 1 || (len == 2 && number[0] == '1')
		|| (len == 2 && number[1] == '0'))
	{
		handle_single_digit(dict, number);
		return ;
	}
	if (len == 2)
	{
		handle_two_digits(dict, number);
		return ;
	}
	if (len >= 3)
	{
		convert_large_number_to_words(dict, number);
		return ;
	}
}

int	handle_two_args(char *arg, char *number)
{
	if (!is_valid_number(arg))
	{
		print_error("Error\n");
		return (1);
	}
	ft_strncpy(number, arg, BUFFER_SIZE);
	number[BUFFER_SIZE - 1] = '\0';
	return (0);
}

int	handle_three_args(char *arg1,
		char *arg2, const char **dict_filename, char *number)
{
	*dict_filename = arg1;
	if (!is_valid_number(arg2))
	{
		print_error("Error\n");
		return (1);
	}
	ft_strncpy(number, arg2, BUFFER_SIZE);
	number[BUFFER_SIZE - 1] = '\0';
	return (0);
}

int	handle_args(int argc, char **argv, char *number, const char **dict_filename)
{
	if (argc == 2)
		return (handle_two_args(argv[1], number));
	else if (argc == 3)
		return (handle_three_args(argv[1], argv[2], dict_filename, number));
	else
	{
		print_error("Error\n");
		return (1);
	}
}
