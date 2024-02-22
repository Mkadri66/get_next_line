/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2024/02/22 21:02:33 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *temp)
{
    long bytes_read;
    char *buffer;

    bytes_read = 1;
    buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
    if(!buffer)
        return(NULL);
    while (bytes_read > 0 && !ft_strchr(temp, '\n')) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(buffer);
            return(NULL);
        }
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(temp, buffer);
    }
    free(buffer);
    return (temp);
}


char *make_line(char *temp)
{
	unsigned long	i;
	char	*line;
	
    i = 0;
    if(!temp[i])
        return(NULL);
	while(temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = (char *) malloc((i + 2) * sizeof(char));
    if(!line)
        return(NULL);
	i = 0;
	while(temp[i] != '\n' && temp[i] != '\0')
	{
		line[i] = temp[i];
		i++;
	}
    if(temp[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
	line[i] = '\0';
	return (line);
}
char *clean_temp(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}
char *get_next_line(int fd) {
    static char *temp;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    //printf(" temp 1 : %s \n", temp);
    temp = read_line(fd, temp);
    //printf(" temp 2 : %s \n", temp);
    line = make_line(temp);
    if (!line)
	{
		free(temp);
		return (NULL);
	}
    //printf(" Line : %s", line);
    temp = clean_temp(temp);
    return (line);
}

// int main() {
//     int fileDescriptor = open("file.txt", O_RDONLY);
    
//     char *line;

//     while((line = get_next_line(fileDescriptor)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fileDescriptor);

//     return 0;
// }
