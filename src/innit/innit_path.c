/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** innit_path
*/
#include "amazed.h"
#include "my.h"
#include "stdlib.h"

static int check_line(char *str)
{
    int i = 0;
    int is_alpha = 1;

    while (str[i] != '\0' && is_alpha) {
        if (str[i] != ' ' && str[i] != '\n')
            is_alpha = is_letter(str[i]) || is_digit(str[i]);
        i++;
    }
    return is_alpha;
}

static char *get_string_begin(char **cells)
{
    int len_cells = 0;
    int begin = 0;

    for (; cells[len_cells] != NULL; len_cells++);
    for (; cells[begin] != NULL; begin++) {
        if (my_strcmp(cells[begin], cells[len_cells - 1]) == 0)
            break;
    }
    if (cells[0] != NULL)
        return cells[len_cells - 1];
    return cells[len_cells];
}

static int check_first_error(amazed_t *amazed, int i, char **info)
{
    int len = 0;

    if (my_strchr(TAB[i], '-') == NULL)
        return 1;
    for (; info[len] != NULL; len++);
    if (len != 2 || (info[len - 1][0] == '\0' || info[len - 1][0] == '\n'))
        return 1;
    if (check_line(info[0]) != 1 || check_line(info[1]) != 1)
        return 1;
    return 0;
}

static int check_name(char **tab_name, char **info)
{
    int cpt_name = 0;

    for (int i = 0; tab_name[i] != NULL; i++) {
        if (my_strcmp(tab_name[i], info[1]) == 0
            || my_strcmp(tab_name[i], info[0]) == 0)
            cpt_name++;
    }
    if (cpt_name == 0)
        return 1;
    cpt_name = 0;
    return 0;
}

static int get_begin(amazed_t *amazed, char *string_begin)
{
    int begin = 0;

    if (amazed == NULL || string_begin == NULL)
        return -1;
    for (; TAB[begin] != NULL; begin++) {
        if (my_strcmp(TAB[begin], string_begin) == 0)
            break;
    }
    return begin;
}

char **innit_path(amazed_t *amazed, char **tab_name, char **cells)
{
    char **path = malloc(sizeof(char *));
    char **info = NULL;
    char *string_begin = get_string_begin(cells);
    int begin = get_begin(amazed, string_begin);

    path[0] = NULL;
    if (begin == -1 || TAB[begin + 1] == NULL)
        return path;
    for (int i = begin + 1; TAB[i] != NULL; i++) {
        if (TAB[i][0] == '#' || (TAB[i][1] == '\0' && TAB[i][1] == '#'))
            continue;
        info = my_str_to_word_array(TAB[i], "-");
        if (check_first_error(amazed, i, info) == 1)
            return path;
        check_backslash_n(amazed, i);
        if (check_name(tab_name, info) == 1)
            return path;
        path = my_realloc(path, TAB[i]);
    }
    return path;
}
