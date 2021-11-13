/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:07:50 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/13 04:19:38 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 50
#endif
char	*get_next_line(int fd);
size_t	ft_strlen_bns(char *s);
char	*ft_strchr_bns(char *s, int c);
char	*ft_strjoin_bns(char *left_str, char *buff);

#endif