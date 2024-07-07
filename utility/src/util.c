/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:22:02 by timmi             #+#    #+#             */
/*   Updated: 2024/07/06 17:22:46 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	while (n-- > 0)
	{
		if (!*src)
			*dest++ = '\0';
		else
			*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(char *src)
{
	int	n;

	n = 0;
	while (src[n])
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*a;
	int		len;

	len = ft_strlen(src);
	a = (char*)malloc((len * sizeof(char)) + 1);
	if (a == NULL)
		return (a);
	while (*src)
		*a++ = *src++;
	*a = '\0';
	return (a);
}

char	ft_strchr(char *str, char c)
{
	while (*str++)
	{
		if (*str == c)
			return (*str);
	}
	return (0);
}

int	ft_is_digit(int n)
{
	if (n % 1 == 0)
		return (1);
	else
		return (0);
}

char *ft_strcat(char *dest, char *src)
{
	char *start;

	start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	return (start);
}