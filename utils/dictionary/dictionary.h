/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:38 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:12:11 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../functions.h"

typedef struct s_dict_entry
{
	char				*number;
	char				*word;
	struct s_dict_entry	*next;
}	t_dict_entry;

typedef struct s_line_info
{
	char	*line;
	size_t	len;
	size_t	capacity;
}	t_line_info;

t_dict_entry	*load_dictionary(const char *filename);
char			*get_word(t_dict_entry *dict, const char *number);
void			free_dictionary(t_dict_entry *dict);

#endif