/*
** EPITECH PROJECT, 2023
** C-POOL
** File description:
** my_strstr.c
*/
#include "my.h"
#include <stdio.h>

char *my_strstr(char *str, const char *to_find)
{
    int to_find_len = my_strlen(to_find);

    while (*str) {
        if (my_strncmp(str, to_find, to_find_len) == 0) {
            return str;
        }
        str++;
    }
    return NULL;
}
