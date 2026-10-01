/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_word_array_to_str
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

char *concatenate_strings(char **strings)
{
    int total_length = 0;
    int len = 0;
    char *result = NULL;
    int current_position = 0;

    for (; strings[len] != NULL; len++);
    for (int i = 0; i < len; i++)
        total_length += my_strlen(strings[i]);
    result = malloc(sizeof(char *) * (total_length + 1));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        my_strcpy(result + current_position, strings[i]);
        current_position += my_strlen(strings[i]);
    }
    return result;
}
