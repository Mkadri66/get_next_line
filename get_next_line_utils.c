/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:29 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/09 20:02:25 by mkadri           ###   ########.fr       */
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
char	*ft_strjoin(char const *str1, char const *str2)
{
	int		total_size;
	char	*str_cat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_size = ft_strlen(str1) + ft_strlen(str2);
	str_cat = malloc((total_size + 1) * sizeof(char));
	if (!str_cat || (!str1 || !str2))
		return (NULL);
	while (str1[i] != '\0')
		str_cat[j++] = str1[i++];
	i = 0;
	while (str2[i] != '\0')
		str_cat[j++] = str2[i++];
	str_cat[j] = '\0';
	return (str_cat);
}