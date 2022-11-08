/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:56 by yloutfi           #+#    #+#             */
/*   Updated: 2022/11/08 19:39:05 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_memchr(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	char	*q;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	q = ptr;
	while (*s1)
	{
		*q = *s1;
		q++;
		s1++;
	}
	*q = '\0';
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	str = (char *)s;
	if (start + len > ft_strlen(str))
		len = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	i = 0;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (0);
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*res;
	char	*q;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	q = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (q == NULL)
		return (0);
	res = q;
	i = 0;
	while (s1[i] && i < ft_strlen(s1))
		*res++ = s1[i++];
	i = 0;
	while (s2[i] && i < ft_strlen(s2))
		*res++ = s2[i++];
	*res = '\0';
	return (q);
}
