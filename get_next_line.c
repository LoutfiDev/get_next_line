/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:58 by yloutfi           #+#    #+#             */
/*   Updated: 2022/11/05 14:53:17 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	int		bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, buff, 10);
	if (!bytes_read)
		return (NULL);
	return (buff);
}

int	main(void)
{
	char	*buffer;
	int		fd;

	fd = open("test.txt", O_RDONLY, 0);
	buffer = get_next_line(fd);
	printf("%s\n", buffer);
	return (0);
}
