/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:29 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/13 17:16:49 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char *str1, char *str2)
{
	int		total_size;
	char	*str_cat;
	int		i;
	int		j;

	if (!str1)
	{
		str1 = malloc (sizeof(char) * 1);
		str1[0] = '\0';
	}
	i = 0;
	j = 0;
	total_size = ft_strlen(str1) + ft_strlen(str2);
	str_cat = malloc((total_size + 1) * sizeof(char));
	if (!str1 || !str2)
		return (NULL);
	while (str1[i] != '\0')
		str_cat[j++] = str1[i++];
	i = 0;
	while (str2[i] != '\0')
		str_cat[j++] = str2[i++];
	str_cat[j] = '\0';
	return (str_cat);
}


char	*ft_strchr(const char *str, int searched_char)
{
	while (*str != '\0' && *str != (char) searched_char)
		str++;
	if (*str == (char) searched_char)
	{
		return ((char *) str);
	}
	return (0);
}