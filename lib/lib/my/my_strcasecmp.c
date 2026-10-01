/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** my_strcasecmp
*/
#include <stdio.h>

int my_strcasecmp(const char *str1, const char *str2)
{
    char char1 = '\0';
    char char2 = '\0';
    int i = (*str1 >= 'A' && *str1 <= 'Z') ? (*str1 + 32) : *str1;
    int j = (*str2 >= 'A' && *str2 <= 'Z') ? (*str2 + 32) : *str2;
    int k = i - j;

    while (*str1 && *str2) {
        char1 = (*str1 >= 'A' && *str1 <= 'Z') ? (*str1 + 32) : *str1;
        char2 = (*str2 >= 'A' && *str2 <= 'Z') ? (*str2 + 32) : *str2;
        if (char1 != char2) {
            return char1 - char2;
        }
        str1++;
        str2++;
    }
    return k;
}
