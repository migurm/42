/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelr <miguelr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:18:46 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/16 11:59:59 by miguelr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strdup(const char *str);
char			*ft_strchar(const char *str, int c);
unsigned int	ft_strlen(const char *str);
char			*fill_buffer(char *buffer, int fd);
char			*get_clear_line(char *buffer);
char			*clean_buffer(char *old_buffer);

#endif