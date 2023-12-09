/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:04 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/09 20:04:18 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GNL_H
# define GNL_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif


char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
#endif
