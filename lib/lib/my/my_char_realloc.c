/*
** EPITECH PROJECT, 2023
** realloc
** File description:
** reallocate a char * in another char *
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_char_realloc(char *old_char, char caract_to_add)
{
    int nbr_caract = 0;
    int new_nbr_caract = 0;
    int i = 0;
    char *new_char;

    while (old_char[nbr_caract] != '\0') {
        nbr_caract++;
    }
    new_nbr_caract += nbr_caract + 1;
    new_char = malloc(sizeof(char *) * (new_nbr_caract + 1));
    while (i < nbr_caract) {
        new_char[i] = old_char[i];
        i++;
    }
    new_char[new_nbr_caract - 1] = caract_to_add;
    new_char[new_nbr_caract] = '\0';
    return new_char;
}
