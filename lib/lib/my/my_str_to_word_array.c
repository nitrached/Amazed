/*
** EPITECH PROJECT, 2023
** C-POOL
** File description:
** my_str_to_word_array.c
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char char_word(char *str, int n, int nl, char *delimiters)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && !my_strchr(delimiters, str[i])) {
            sp = 0;
            nb++;
        }
        sp = (my_strchr(delimiters, str[i])) ? 1 : 0;
        let += (!my_strchr(delimiters, str[i]) && nb == n) ? 1 : 0;
        if (let == nl)
            return str[i];
        i++;
    }
    return '\0';
}

int nb_char(char *str, int n, char *delimiters)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && !my_strchr(delimiters, str[i])) {
            sp = 0;
            nb++;
        }
        sp = (my_strchr(delimiters, str[i])) ? 1 : 0;
        let += (!my_strchr(delimiters, str[i]) && nb == n) ? 1 : 0;
        i++;
    }
    return let;
}

int nb_word(char *str, char *delimiters)
{
    int i = 0;
    int sp = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (sp == 1 && !my_strchr(delimiters, str[i])) {
            sp = 0;
            nb++;
        }
        sp = (my_strchr(delimiters, str[i])) ? 1 : 0;
        i++;
    }
    return nb;
}

char **my_str_to_word_array(char *str, char *delimiters)
{
    int y = 0;
    int x = 0;
    char **tab = malloc(sizeof(char *) * (nb_word(str, delimiters) + 1));

    while (y < nb_word(str, delimiters)) {
        tab[y] = malloc(sizeof(char) * (nb_char(str, y + 1, delimiters) + 1));
        x = 0;
        while (x < nb_char(str, y + 1, delimiters)) {
            tab[y][x] = char_word(str, y + 1, x + 1, delimiters);
            x++;
        }
        tab[y][x] = '\0';
        y++;
    }
    tab[y] = 0;
    return tab;
}
