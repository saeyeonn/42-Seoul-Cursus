/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:41:32 by saelim            #+#    #+#             */
/*   Updated: 2023/04/20 16:54:49 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_free(char **str);
char	*re_storage(char *storage);
char	*new_line(char *storage);
char	*readbuf(int fd, char *storage);

#endif
