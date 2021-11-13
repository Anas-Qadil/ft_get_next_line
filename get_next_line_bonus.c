/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:43:49 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/13 03:34:15 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_the_buffer_bns(char *str, int fd)
{
	char *buffer;
	int byte_read;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	byte_read = 1;
	while (ft_strchr_bns(str, '\n') == NULL && byte_read != 0)	
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		str = ft_strjoin_bns(str, buffer);
	}
	free(buffer);
	return (str);
} 

char *get_line_bns(char *str)
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

char *remove_readed_line_bns(char *str)
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
	buff = malloc(ft_strlen_bns(str) - i + 1);
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
	static char *str[6500];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_the_buffer_bns(str[fd], fd);
	if (str[fd] == NULL)
		return (NULL);
	line = get_line_bns(str[fd]);
	str[fd] = remove_readed_line_bns(str[fd]);
	return (line);
}

