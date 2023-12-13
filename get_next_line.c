/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/13 17:29:46 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_make_line(char *str)
{

}



char *get_next_line(int fd) {
    static char *temp;
    char *buffer;
    char *line;
    int bytesRead;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    temp = NULL;
    bytesRead = 1;
    buffer =  (char *)malloc(BUFFER_SIZE + 1  * sizeof(char));
    if (temp == NULL) {
        temp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
    } else 
        temp[0] = '\0';
    while (bytesRead > 0 && !ft_strchr(temp, '\n')) {
        
        bytesRead = read(fd, buffer, sizeof(buffer));
        temp = ft_strjoin(temp, buffer);
    }
    free(buffer);
    line = ft_make_line(temp);
    // a faire filtrer la ligne jusqu au \n
    // recuperer le surplus pour le mettre dans static 
    printf("%s\n", temp);

    return (temp);
}

int main() {
    // Exemple d'utilisation
    int fileDescriptor = open("file.txt", O_RDONLY);
    if (fileDescriptor < 0) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    get_next_line(fileDescriptor);
    get_next_line(fileDescriptor);
    //get_next_line(fileDescriptor);


    close(fileDescriptor);

    return 0;
}
