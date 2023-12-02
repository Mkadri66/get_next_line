/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:26:04 by mkadri            #+#    #+#             */
/*   Updated: 2023/12/02 21:15:00 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H


# ifndef BUFFER_SIZE
# define BUFFER_SIZE = 5
# endif


char	*get_next_line(int fd);

#endif
