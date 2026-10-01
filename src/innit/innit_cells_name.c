/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** innit_cells_name
*/
#include "amazed.h"
#include "my.h"
#include <stdlib.h>

int check_name(char **cells_name, char **cells)
{
    int cpt = 0;

    for (int p = 0; cells_name[p] != NULL; p++) {
        if (my_strcmp(cells_name[p], cells[0]) == 0)
            cpt++;
    }
    return cpt;
}

char **innit_cells_name(char **cell, amazed_t *amazed)
{
    char **cells_name = malloc(sizeof(char *));
    char **cells = NULL;
    int cpt = 0;

    cells_name[0] = NULL;
    for (int i = 0; cell[i] != NULL; i++) {
        cells = my_str_to_word_array(cell[i], " ");
        cpt = check_name(cells_name, cells);
        if (cpt != 0) {
            cell[i] = NULL;
            amazed->to_return = 84;
            return cells_name;
        }
        if (cells[0][0] != '#')
            cells_name = my_realloc(cells_name, cells[0]);
    }
    return cells_name;
}
