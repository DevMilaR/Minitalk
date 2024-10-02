#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int    i;

	i = 0;
    if (s && f)
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}

#include <stdio.h>

// Función que imprime el carácter y su índice
void print_char_index(unsigned int index, char *c)
{
    printf("Index: %u, Char: %c\n", index, *c);
}
