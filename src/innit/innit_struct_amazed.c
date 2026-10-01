/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** innit
*/
#include "amazed.h"
#include <stdio.h>
#include <stdlib.h>

int count_space(char *line)
{
    int i = 0;

    for (; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t')
            break;
    }
    return i;
}

static char **fill_tab(void)
{
    char **tab = malloc(sizeof(char *));
    size_t num_lines = 0;
    ssize_t read;
    char *line = NULL;
    size_t len = 0;

    tab[0] = NULL;
    read = getline(&line, &len, stdin);
    while (read != -1) {
        num_lines++;
        tab = my_realloc(tab, line);
        read = getline(&line, &len, stdin);
    }
    return tab;
}

static path_t *innit_all_path(void)
{
    path_t *path = malloc(sizeof(path_t));

    if (path == NULL)
        return NULL;
    path->cells = NULL;
    path->nb_cells = 0;
    return path;
}

static list_t *innit_linked_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->start = NULL;
    list->end = NULL;
    return list;
}

int check_backslashn_file(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == '\n') {
            tab[i] = NULL;
            return 84;
        }
    }
    return 0;
}

amazed_t *innit_struct(void)
{
    amazed_t *amazed = malloc(sizeof(amazed_t));

    if (amazed == NULL)
        return NULL;
    amazed->to_return = 0;
    amazed->nb_path = 0;
    amazed->tab = fill_tab();
    if (check_backslashn_file(amazed->tab) == 84)
        amazed->to_return = 84;
    amazed->robot_nb = -1;
    amazed->all_path = innit_all_path();
    amazed->maze = innit_linked_list();
    return amazed;
}
