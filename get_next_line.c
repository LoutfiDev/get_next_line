/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:58 by yloutfi           #+#    #+#             */
/*   Updated: 2022/11/06 21:23:22 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (*buffer == '\0')
		return (NULL);
	line = malloc((ft_strlen(buffer) + 1) * sizeof(char));
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			line[i++] = '\n';
			break ;
		}
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			bytes_read;
	int			line_len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bytes_read = 0;
	if (!buff)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (!bytes_read)
			return (NULL);
		buff[bytes_read] = 0;
	}
	line = malloc((bytes_read + 1) * sizeof(char));
	line = get_line(buff);
	if (!line)
		return (NULL);
	line_len = ft_strlen(line);
	buff = strdup(buff + line_len);
	return (line);
}

int	main(void)
{
	char	*buffer;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY, 0);
	i = 0;
	while (i < 9)
	{	
		buffer = get_next_line(fd);
		printf("%s", buffer);
		i++;
	}
	return (0);
}
