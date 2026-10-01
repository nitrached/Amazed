/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_strcat_malloc
*/
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *my_strcat_malloc(char *dest, char const *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * (dest_len + my_strlen(src) + 1));

    my_strcpy(tmp, dest);
    my_strcpy(&tmp[my_strlen(tmp)], src);
    tmp[my_strlen(src) + dest_len] = '\0';
    return tmp;
}
