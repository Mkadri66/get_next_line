/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/09 20:07:40 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	char *temp = NULL;
	//char	*buffer; 

	int  bytesRead;

	if(fd < 0 || BUFFER_SIZE <= 0 )
		return(NULL);
	char buffer[BUFFER_SIZE];
		
    temp = (char *) malloc((BUFFER_SIZE) * sizeof(char));
	
	bytesRead = read(fd, buffer, sizeof(buffer));

    temp = ft_strjoin(temp, buffer);

    printf("%s \n", temp);
	
	bytesRead = read(fd, buffer, sizeof(buffer));

    temp = ft_strjoin(temp, buffer);

    printf("%s \n", temp);
    close(fd);

	return("\n test");	
}

int	main(int argc, char **argv)
{
	int		fd;
	
	fd = open("file.txt", O_RDONLY);
	
	get_next_line(fd);
	//printf("%s", line);
	fd = close(fd);
	return (0);
}