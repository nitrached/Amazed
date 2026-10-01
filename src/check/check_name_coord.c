/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** check_name_coord
*/
#include "amazed.h"
#include <stdio.h>

static int check_space(char *line)
{
    int cpt = 0;
    char **tab = my_str_to_word_array(line, " \t");

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#')
            return 2;
    }
    for (; tab[cpt] != NULL; cpt++);
    if (cpt == 3)
        return 2;
    else
        cpt = 0;
    return cpt;
}

static int check_str_isnum(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#')
            return 0;
        if (is_digit(line[i]) == 0)
            return -1;
    }
    return 0;
}

static int check_error_line(char **cells, int i)
{
    char **info = my_str_to_word_array(cells[i], " ");
    int len = 0;

    if (info[0][0] == '#')
        return 0;
    for (; info[len] != NULL; len++);
    if (len != 3)
        return 84;
    if (my_str_isalpha(info[0]) != 1)
        return 84;
    if ((check_str_isnum(info[1]) == -1 || check_str_isnum(info[2]) == -1))
        return 84;
    return 0;
}

int check_name_coord(char **cells)
{
    for (int i = 0; cells[i] != NULL; i++) {
        if (check_space(cells[i]) != 2) {
            cells[i] = NULL;
            return 84;
        }
    }
    for (int i = 0; cells[i] != NULL; i++) {
        if (check_error_line(cells, i) == 84) {
            cells[i] = NULL;
            return 84;
        }
    }
    return 0;
}
