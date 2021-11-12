/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:05:46 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/12 02:45:05 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_the_buffer(char *str, int fd)
{
	char *buffer;
	int byte_read;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	byte_read = 1;
	while (ft_strchr(str, '\n') == NULL && byte_read != 0)	
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
} 

char *get_line(char *str)
{
	char *line;
	int	i;
	int j;

	j = 0;
	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}

	if (str[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

char *remove_readed_line(char *str)
{
	char *buff;
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	buff = malloc(ft_strlen(str) - i + 1);
	if (buff == NULL)
		return (NULL);
	i++;
	while (str[i])
	{
		buff[j] = str[i];
		j++;
		i++;
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}
char	*get_next_line(int fd)
{
	static char *str;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_the_buffer(str, fd);
	if (str == NULL)
		return (NULL);
	line = get_line(str);
	str = remove_readed_line(str);
	return (line);
}