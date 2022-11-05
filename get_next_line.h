/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:52 by yloutfi           #+#    #+#             */
/*   Updated: 2022/11/05 14:53:43 by yloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

# include <unistd.h>
# include <fcntl.h>  
# include <stdlib.h>
/*just for test*/
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);

#endif