/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:04 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/21 17:49:12 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, int searched_char);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *array, int value, size_t count);

#endif