/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/02 21:10:28 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


char	*get_next_line(int fd)
{
	static	char *tmp = NULL;

	if(fd < 0 || BUFFER_SIZE <= 0 )
		return(NULL);
	printf("%d", BUFFER_SIZE);
	return("Hello");	
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
		line = get_next_line(fd);
		printf("%s", line);
	fd = close(fd);
	return (0);
}