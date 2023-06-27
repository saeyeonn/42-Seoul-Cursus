#include <unistd.h>
#include <stdlib.h>
# define BUFFER_SIZE 10

int     ft_strlen(char *str)
{
    int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int ft_strchr(char *line)
{
	int i = -1;

	while (line[++i])
		if (line[i] == '\n')
			return 1;

	return 0;
}

char    *ft_strjoin(char *remains, char *buffer)
{
    int i, j, k = 0;

    if (!remains && !buffer)
        return (NULL);
    unsigned int size = ft_strlen(remains) + ft_strlen(buffer);
    char *array = (char *)malloc(size + 1);
    if (!(array ))
        return (NULL);
    
    while (remains[i])
        array[j++] = remains[i++]; 
    while (buffer[k])
        array[j++] = buffer[k++];
    array[size] = '\0';
    free((void *)remains);
    
    return array;
}

char    *one_line(char *remains)
{
    int i, j, k = 0;

    while (remains[i] && remains[i] != '\n')
        i++;
    if (remains[i] == '\n')
		i++;

    char *array = (char *)malloc(sizeof(char) * (i + 1));
    if (!array)
        return NULL;

    while (remains[j] && remains[k] != '\n')
        array[j++] = remains[k++];

	if (remains[j] == '\n')
	{
		array[j] = '\n';
		array[j + 1] = '\0';
		return (array);
	}
    array[j] = '\0';

    return array;
}

char    *cut_next_line(char *remains)
{
    int i, j = 0;


    while (remains[i] && remains[i] != '\n')
        i++;
    if (!remains[i])
    {
        free(remains);
        return NULL;
    }

    char *array = (char *)malloc(ft_strlen(remains) - i + 1);
    if (!array)
        return NULL;
    
    i++;
    while (remains[i])
        array[j++] = remains[i++];
    array[j] = '\0';
    free(remains);

    return array;
}

char     *get_next_line(int fd)
{
    if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return NULL;

    int count  = 1;
    static char *remains;
    char buffer[BUFFER_SIZE + 1];
    buffer[0] = '\0';

    while (!ft_strchr(buffer) && count != 0)
    {
        count = read(fd, buffer, BUFFER_SIZE);
        if (count < 0)
            return NULL;
        buffer[count] = '\0';
        remains = ft_strjoin(remains, buffer);
    }
    
    char *line = one_line(remains);
    remains = cut_next_line(remains);

    if (line[0] == '\0') 
    {
        free(line);
        return NULL;
    }

    return line;
}