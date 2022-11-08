/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:58 by yloutfi           #+#    #+#             */
/*   Updated: 2022/11/08 21:46:59 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *haystack, char *line)
{
	int		i;

	i = 0;
	while (haystack[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	i = 0;
	while (haystack[i] != '\n')
	{
		line[i] = haystack[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	haystack = ft_substr(haystack, ft_strlen(line), ft_strlen(haystack));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*haystack;
	char		*buff;
	int			bytes_read;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = -1;
	while (!ft_memchr(buff, '\n', BUFFER_SIZE) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = 0;
		if (bytes_read < 0)
			return (NULL);
		haystack = ft_strjoin(haystack, buff);
	}
	free(buff);
	ft_get_line(haystack, buff);
	return (buff);
}

int	main(void)
{
	char	*buffer;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY, 0);
	i = 0;
	while (i < 3)
	{
		buffer = get_next_line(fd);
		printf("%s", buffer);
		i++;
	}

	return (0);
}
