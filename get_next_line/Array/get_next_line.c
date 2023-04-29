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

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*re_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n'); // location of \n
	if (!ptr) // X existence of \n
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1; // len of 
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len); 
	ft_free(&storage); // free original storage
	if (!new_storage) // failed to make new storage
		return (NULL);
	return (new_storage); // modified storage (removed printed letters)
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n'); // location of \n
	len = (ptr - storage) + 1; // location of 1st letter of print line
	line = ft_substr(storage, 0, len); //make 1 line to print
	if (!line) // failed to make line
		return (NULL);
	return (line); // success
}

char	*readbuf(int fd, char *storage)
{
	int		flag;
	char	*buffer;

	flag = 1; // gonna be read count value
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer) // allocation failed -> free static storage 
		return (ft_free(&storage)); // == return NUll
	while (flag > 0 && !ft_strchr(buffer, '\n')) // repeat until find \n -> add to storage
	{
		flag = read (fd, buffer, BUFFER_SIZE); // save read count in flag
		storage = ft_strjoin(storage, buffer); // save read letters
	}
	free(buffer); // after found \n -> to restart buffer || finish all
	if (flag == -1) // read error (commonly EOF)
		return (ft_free(&storage)); // free static storage -> return NULL
	return (storage); // return all letters read & saved
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0) // fd error
		return (NULL); // return value rules of mandatory - NULL
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = readbuf (fd, storage); // save read letters in stroage
	if (!storage) // couldn't read anything
		return (NULL); // return value rules of mandatory - NULL
	line = new_line(storage); // for print 1 line
	if (!line)
		return (ft_free(&storage)); // return value rules of mandatory - NULL
	storage = re_storage(storage); // modify saved letters in static variable for next loop
	return (line); // print 1 line
}
