/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:36:24 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 00:36:25 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

int		ft_strlen(const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *src);

#endif
