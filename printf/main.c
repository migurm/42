#include "ft_printf.h"
#include <stdio.h>

int main() {
    // Prueba de caracteres
    ft_printf("Char: %c\n", 'A');
    
    // Prueba de cadenas
    ft_printf("String: %s\n", "Hello, World!");

    // Prueba de punteros
    int a = 42;
    ft_printf("Pointer: %p\n", &a);

    // Prueba de enteros con signo
    ft_printf("Signed int: %d\n", 12345);
    ft_printf("Signed int: %d\n", -12345);

    // Prueba de enteros sin signo
    ft_printf("Unsigned int: %u\n", 12345);

    // Prueba de hexadecimales en minúsculas
    ft_printf("Hex (lowercase): %x\n", 255);

    // Prueba de hexadecimales en mayúsculas
    ft_printf("Hex (uppercase): %X\n", 255);

    // Prueba del carácter '%'
    ft_printf("Percent: %%\n");

    // Prueba combinada
    ft_printf("Combined: Char: %c, String: %s, Pointer: %p, Signed: %d, Unsigned: %u, Hex (lower): %x, Hex (upper): %X, Percent: %%\n",
              'Z', "Combined Test", &a, -789, 789, 789, 789);

    // Prueba con valores extremos
    ft_printf("Max unsigned int: %u\n", 4294967295U);
    ft_printf("Max signed int: %d\n", 2147483647);
    ft_printf("Min signed int: %d\n", -2147483648);

    return 0;
}

/* Para compilar todo y ejecutar las pruebas hay q hacer:
1-> cc -Wall -Wextra -Werror -o test_printf main.c libftprintf.a
2-> ./test_printf
 */

/*
Bueno antes de lo anterior, obviamente hay q hacer en el directorio de printf:
make

Y cuando acabemos.
make clean
make fclean
*/