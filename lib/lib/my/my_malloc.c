/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_malloc
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void *my_malloc(int size, int is_pointer)
{
    void *result;

    if (is_pointer == 0) {
        result = malloc(sizeof(char) * (size + 1));
    } else if (is_pointer == 1) {
        result = malloc(sizeof(char *) * (size + 1));
    } else {
        my_putstr("Type invalide. 0 is for char *, 1 is for char **\n");
        return NULL;
    }
    if (result == NULL) {
        my_putstr("Memory allocation error\n");
        return NULL;
    }
    if (is_pointer == 0)
        ((char *)result)[size] = '\0';
    if (is_pointer == 1)
        ((char **)result)[size] = NULL;
    return result;
}
