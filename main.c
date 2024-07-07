/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:10:06 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 02:46:32 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils/dictionary/dictionary.h"
#include "utils/main_helpers/main_helpers1.h"
#include "utils/main_helpers/main_helpers2.h"
#include "utils/main_helpers/main_helpers3.h"
#include "utils/functions.h"

#define DEFAULT_DICT "dict/en.dict"
#define BUFFER_SIZE 1024

int	main(int argc, char **argv)
{
	const char		*dict_filename;
	char			number[BUFFER_SIZE];
	t_dict_entry	*dict;

	dict_filename = DEFAULT_DICT;
	ft_bzero(number, BUFFER_SIZE);
	if (handle_args(argc, argv, number, &dict_filename))
		return (1);
	dict = load_dictionary(dict_filename);
	if (!dict)
	{
		print_error("Dict Error\n");
		return (1);
	}
	convert_number_to_words(dict, number);
	free_dictionary(dict);
	return (0);
}
