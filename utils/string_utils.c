/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:48:06 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/06 22:55:47 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	ft_strlen(const char *src)
{
	int	n;

	n = 0;
	while (src[n])
		n++;
	return (n);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	char	*a;
	int		len;
	int		i;

	len = ft_strlen(src);
	a = malloc((len * sizeof(char)) + 1);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = src[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
