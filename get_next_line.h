/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:05:48 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/12 03:06:38 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_GET_NEXT_LINE_
# define FT_GET_NEXT_LINE_
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char    *remove_readed_line(char *str);
char    *get_line(char *str);
char	*read_the_buffer(char *str, int fd);

#endif