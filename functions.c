char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	while (n-- >= 0)
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
	while (*str1 || *str2)
	{
		if (*str1 < *str2)
			return (*str1 - *str2);
		else if (*str1 > *str2)
			return (*str1 - *str2);
		else
			*str1++;
			*str2++;
	}
	return (0);
}

int	ft_strlen(char *src)
{
	int n;

	n = 0;
	while (src[n])
		n++;
	return  (n);
}

char	*ft_strdup(char *src)
{
	char *a;
	int len;

	len = ft_strlen(src) + 1;
	a = malloc(len * sizeof(char));
	if (a == NULL)
		return a = NULL;
	while (*src)
		*a++ = *src++;
	*a = '\0';
	return (a);
}

char	*ft_strchr(char *str, char c)
{
	while (*str++)
	{
		if (*str == c)
			return (*str);
		else
			return (*str);
	}
}