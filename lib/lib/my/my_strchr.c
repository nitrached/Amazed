/*
** EPITECH PROJECT, 2024
** my
** File description:
** my_strchr
*/
#include <stdio.h>

char *my_strchr(char *chaine, int caractere)
{
    while (*chaine != '\0') {
        if (*chaine == caractere) {
            return (char *)chaine;
        }
        chaine++;
    }
    return NULL;
}
