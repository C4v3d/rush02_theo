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
