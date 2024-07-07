/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:28 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 02:00:18 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stddef.h>

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strlen(const char *src);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, char c);
char	*ft_strcat(char *dest, const char *src);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
char	*trim(char *str);

#endif