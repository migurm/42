/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:18:46 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/11 10:21:12 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Prototipos de las funciones y directivas necesarias, como el tamaño del buffer
(BUFFER_SIZE)
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Elegimos un tamaño de buffer por defecto */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h> // Para read()
# include <stdlib.h> // Para malloc() y free()

//Funciones auxiliares necesarias
char            *get_next_line(int fd);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strdup(const char *str);
char			*ft_strchar(const char *str, int c);
unsigned int	ft_strlen(const char *str);
char            *fill_buffer(char *buffer, int fd);
char            *get_clear_line(char *buffer);
char            *clean_buffer(char *old_buffer);

#endif