/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:38:33 by marvin            #+#    #+#             */
/*   Updated: 2024/07/07 08:38:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
#define UTIL_H

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, int n);
int	ft_strcmp(char *str1, char *str2);
int	ft_strlen(char *src);
char	*ft_strdup(char *src);
char	ft_strchr(char *str, char c);
int	ft_is_digit(int n);

#endif