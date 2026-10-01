/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** $
*/
#include "amazed.h"
#include <stdio.h>

static int check_line(char *str)
{
    int i = 0;
    int is_alpha = 1;

    while (str[i] != '\0' && is_alpha) {
        if (str[i] != ' ')
            is_alpha = is_letter(str[i]) || is_digit(str[i]);
        i++;
    }
    return is_alpha;
}

static int check_start(int i, char **cells)
{
    int cpt_start = 0;

    if (my_strcmp(cells[i], "##start") == 0) {
        cpt_start++;
        if (cells[i + 1] == NULL || cells[i + 1][0] == '\0'
            || check_line(cells[i + 1]) != 1) {
            cells[i] = NULL;
            return 84;
        }
    }
    return cpt_start;
}

static int check_end(int i, char **cells)
{
    int cpt_end = 0;

    if (my_strcmp(cells[i], "##end") == 0) {
        cpt_end++;
        if (cells[i + 1] == NULL || cells[i + 1][0] == '\0'
            || check_line(cells[i + 1]) != 1) {
            cells[i] = NULL;
            return 84;
        }
    }
    return cpt_end;
}

int check_multiple_start_end(char **cells)
{
    int cpt_start = 0;
    int cpt_end = 0;

    for (int i = 0; cells[i] != NULL; i++) {
        cpt_start += check_start(i, cells);
        if (cpt_start >= 84)
            return 84;
        cpt_end += check_end(i, cells);
        if (cpt_end >= 84)
            return 84;
    }
    if (cpt_start != 1 || cpt_end != 1)
        return 84;
    return 0;
}
