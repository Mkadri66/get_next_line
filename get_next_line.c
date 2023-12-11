/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:25:46 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/11 17:52:57 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd) {
    static char *temp = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    char buffer[BUFFER_SIZE];
    int bytesRead;

    // Vérifier si temp a été alloué, sinon l'allouer
    if (temp == NULL) {
        temp = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (temp == NULL) {
            perror("Erreur d'allocation de mémoire");
            exit(EXIT_FAILURE);
        }
    } else {
        // Réinitialiser temp à chaque appel
        temp[0] = '\0';
    }

    bytesRead = read(fd, buffer, sizeof(buffer));

    while (bytesRead > 0) {
        int i = 0;

        while (i < bytesRead && buffer[i] != '\n') {
            char currentChar = buffer[i];

            // Faire quelque chose avec le caractère, par exemple l'ajouter à temp
            char tempChar[2] = {currentChar, '\0'};
            strcat(temp, tempChar);

            // Incrémenter l'index
            i++;
        }

        if (i < bytesRead && buffer[i] == '\n') {
            // Si un retour à la ligne est rencontré, sortir de la boucle externe
			break;
        }

        bytesRead = read(fd, buffer, sizeof(buffer));
    }

    // Afficher la ligne lue
    printf("%s\n", temp);

    return temp;
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
    get_next_line(fileDescriptor);


    close(fileDescriptor);

    return 0;
}
