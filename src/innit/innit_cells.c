/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** innit_cells
*/
#include "amazed.h"
#include <stdio.h>
#include <stdlib.h>

static char **check_start_end(amazed_t *amazed, int i, char **cells)
{
    if (my_strcmp(TAB[i], "##start") == 0 || my_strcmp(TAB[i], "##end") == 0) {
        check_backslash_n(amazed, i);
        cells = my_realloc(cells, TAB[i]);
    }
    return cells;
}

static char **fill_cells(amazed_t *amazed, int i, char **cells)
{
    int cpt = 0;

    for (; TAB[i][cpt] != '\0'; cpt++) {
        if (TAB[i][cpt] == '#' && (TAB[i][cpt + 1]
            != '\0' && TAB[i][cpt + 1] == '#')) {
                check_backslash_n(amazed, i);
                cells = check_start_end(amazed, i, cells);
            break;
        }
        if (TAB[i][cpt] == '#') {
            TAB[i][cpt] = '\0';
            break;
        }
    }
    if (TAB[i][cpt] == '\0') {
        if (TAB[i][cpt - 1] == '\n')
            TAB[i][cpt - 1] = '\0';
        cells = my_realloc(cells, TAB[i]);
    }
    return cells;
}

static int get_nb_robot(amazed_t *amazed)
{
    int begin = 0;

    for (; TAB[begin] != NULL; begin++) {
        check_backslash_n(amazed, begin);
        if (my_str_isnum(TAB[begin]) == 1) {
            amazed->robot_nb = my_getnbr(TAB[begin]);
            break;
        }
    }
    return begin;
}

char **innit_cells(amazed_t *amazed)
{
    char **cells = malloc(sizeof(char *));
    char **info = NULL;
    int begin = get_nb_robot(amazed);

    cells[0] = NULL;
    if (amazed->robot_nb == -1)
        return cells;
    for (int i = begin + 1; TAB[i] != NULL; i++) {
        if (TAB[i][0] != '\0' && TAB[i][0] == '#'
            && TAB[i][1] != '\0' && TAB[i][1] != '#')
            continue;
        info = my_str_to_word_array(TAB[i], "-");
        if (info == NULL || TAB[i][0] == '-')
            TAB[i] = NULL;
        if (TAB[i] == NULL ||
            (my_str_isalpha(info[0]) == 1 && my_strchr(TAB[i], '-') != NULL))
            break;
        cells = fill_cells(amazed, i, cells);
    }
    return cells;
}
