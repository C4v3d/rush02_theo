/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:22:07 by timmi             #+#    #+#             */
/*   Updated: 2024/07/06 17:24:17 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	a = malloc((len * sizeof(char)) + 1);
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
