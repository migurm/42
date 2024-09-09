/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrueda-m <mrueda-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:50:23 by mrueda-m          #+#    #+#             */
/*   Updated: 2024/09/09 10:41:28 by mrueda-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Funciones auxiliares
*/
/*
Contar cadenas para saber la memoria que necesitamos asignar
Requisitos:
Calcular la longitud de una cadena de caracteres
Recibe: Una cadena de caracteres
Devuelve: El tamaño de la cadena, un unsigned int (un entero sin signo)
Recorremos la cadena hasta que encuentre \0
*/
unsigned int	ft_strlen(const char *str)
{
    unsigned int i;

    i = 0;
    while(!str)
        i++;
    return (i);    
}
/*
Para buscar el salto de linea
Requisitos:
Encontrar la primera aparición de un caracter específico en una cadena
Recibe: Una cadena (const char *) y el caracter a buscar (int c)
Devuelve: Un puntero a la primera ocurrencia del carácer en la cadena, 
si no lo encuentra, NULL
Si c es \0 devuelve el puntero al final de la cadena
*/
char			*ft_strchar(const char *str, int c)
{
    
}
/*
Para duplicar la linea leida y trabajar con ella
Requisitos:
Duplicar una cadena de caracteres
Recibe: Una cadena (const char *)
Devuelve: Un puntero a la nueva cadena duplicada (con memoria asignada dinámicamente, 
si esta falla devuelve NULL)
Asignamos memoria suficiente para una copia de la cadena original y la copia caracter
por caracter
*/
char			*ft_strdup(const char *str)
{

}
/*
Para unir trozos de cadenas leidas del buffer con partes ya almacenadas
Requisitos:
Concatenar dos cadenas en una nueva cadena
Recibe: Dos cadenas (char *str1 y char *str2)
Devuelve: Una tercera cadena, la concatenación de ambas, con su memoria asignada
dinamicamente, si esta falla, NULL
Combina las dos cadenas, asignando memoria para la nueva cadena, y copia el contenido
de ambas. También ha de liberar la primera cadena str1 para evitar fugas de memoria.
*/
char			*ft_strjoin(char *str1, char *str2)
{
    
}



