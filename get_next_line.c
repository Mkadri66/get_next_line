/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2024/02/04 13:13:54 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_line(int fd, char *temp)
{
    long bytes_read;
    char *buffer;

    if(!temp)
        temp = ft_calloc(0, 0);
    bytes_read = 1;
    buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));  
    if (buffer == NULL || temp == NULL) {
        free(buffer);
        free(temp);
        return(NULL);
    }
    while (bytes_read > 0 && !ft_strchr(temp, '\n')) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0)
            temp = ft_strjoin(temp, buffer);
    }
    if (bytes_read <= 0 || bytes_read == 0)
    {
        free(temp);
        return NULL;
    }
    return(temp);
}

char    *make_line(char *temp)
{
	unsigned long		i;
	char 	*line;
	
	i = 0;
	while(temp[i] != '\n')
		i++;
	line = (char *) malloc(i + 1 * sizeof(char));
    if(!line)
    {   
        free(line);
        return(NULL);
    }
	i = 0;
	while(temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}
char *clean_temp(char *str)
{
	int	i;
	char *new_temp;
	
	i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
    }
	new_temp = strdup(str + i + 1);
    free(str);
	return(new_temp);
}
char *get_next_line(int fd) {
    static char *temp;
    char        *line;
    
    line = "";
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    temp = read_line(fd, temp);
	// if (!temp)
	// 	return (NULL);
    line = make_line(temp);
    temp = clean_temp(temp);
    return (line);
}

// int main() {
//     int fileDescriptor = open("file.txt", O_RDONLY);
//     if (fileDescriptor < 0) {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }
    

//     printf("%s",get_next_line(fileDescriptor));
//     printf("%s",get_next_line(fileDescriptor));
//     printf("%s",get_next_line(fileDescriptor));
//     printf("%s",get_next_line(fileDescriptor));
//     printf("%s",get_next_line(fileDescriptor));
//     printf("%s",get_next_line(fileDescriptor));
//     printf("%s",get_next_line(fileDescriptor));
//     printf("%s",get_next_line(fileDescriptor));

//     close(fileDescriptor);

//     return 0;
// }
