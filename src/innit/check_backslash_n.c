/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** check_backslash_n
*/
#include "amazed.h"

int check_backslash_n(amazed_t *amazed, int i)
{
    for (int j = 0; TAB[i][j] != '\0'; j++) {
        if (TAB[i][j] == '\n')
            TAB[i][j] = '\0';
    }
    return 0;
}
