/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2024/02/22 17:00:26 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *temp)
{
    long bytes_read;
    char *buffer;

    bytes_read = 1;
    buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
    if (buffer == NULL) {
        return (NULL);
    }
    while (bytes_read > 0 && !ft_strchr(temp, '\n')) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            temp = ft_strjoin(temp, buffer);
        }
    }
    free(buffer);
    if (bytes_read <= 0 || bytes_read == 0)
    {
        free(temp);
        return NULL;
    }

    return (temp);
}


char *make_line(char *temp)
{
	unsigned long	i;
	char	*line;
	
    if(!temp)
    {
        return(NULL);
    }
	i = 0;
	while(temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = (char *) malloc((i + 2) * sizeof(char));
    if(!line)
    {
        return(NULL);
    }
	i = 0;
	while(temp[i] != '\n' && temp[i] != '\0')
	{
		line[i] = temp[i];
		i++;
	}
    if(temp[i] == '\n')
    {
        line[i++] = '\n';
    }
	line[i] = '\0';
	return (line);
}
char *clean_temp(char *str)
{
	int		i;
	char	*new_temp;

    if(!str)
    {
        return(NULL);
    }
	i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
    }
    if (str[i] == '\0')
    {
        free(str);
        return (NULL);
    }
	new_temp = ft_strdup(str + i + 1);
    free(str);
	return(new_temp);
}
char *get_next_line(int fd) {
    static char *temp;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    temp = read_line(fd, temp);
    line = make_line(temp);
    if (!line)
	{
		free(temp);
		return (NULL);
	}
    temp = clean_temp(temp);
    return (line);
}

int main() {
    int fileDescriptor = open("file.txt", O_RDONLY);
    if (fileDescriptor < 0) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    

    char *line;

    while((line = get_next_line(fileDescriptor)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fileDescriptor);

    return 0;
}
