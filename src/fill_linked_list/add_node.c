/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** add_node
*/
#include "amazed.h"
#include <stdio.h>
#include <stdlib.h>

static int check_if_plus_null_start(get_info_t *info, int i, node_t **tab_node,
    amazed_t *amazed)
{
    char **tab_info = NULL;

    if (my_strcmp(info->cells[i], "##start") == 0) {
        if (info->cells[i + 1] == NULL) {
            tab_node[0] = NULL;
            return 1;
        }
        tab_info = my_str_to_word_array(info->cells[i + 1], " ");
        tab_node[0]->coordx = my_getnbr(tab_info[1]);
        tab_node[0]->coordy = my_getnbr(tab_info[2]);
        tab_node[0]->name = my_strdup(tab_info[0]);
        tab_node[0]->next = NULL;
        tab_node[0]->previous = NULL;
        tab_node[0]->distance_end = -1;
        tab_node[0]->occupied = 0;
        tab_node[0]->name_robot = return_name_robots(amazed);
    }
    return 0;
}

static void fill_start_node(get_info_t *info, node_t **tab_node,
    amazed_t *amazed)
{
    for (int i = 0; info->cells[i] != NULL; i++) {
        if (check_if_plus_null_start(info, i, tab_node, amazed) == 1)
            return;
    }
}

static int check_if_plus_null_end(get_info_t *info, int i, node_t **tab_node,
    amazed_t *amazed)
{
    int cpt = 0;
    char **tab_info = NULL;

    for (; info->cells_name[cpt] != NULL; cpt++);
    if (my_strcmp(info->cells[i], "##end") == 0) {
        if (info->cells[i + 1] == NULL) {
            tab_node[cpt - 1] = NULL;
            return 1;
        }
        tab_info = my_str_to_word_array(info->cells[i + 1], " ");
        tab_node[cpt - 1]->coordx = my_getnbr(tab_info[1]);
        tab_node[cpt - 1]->coordy = my_getnbr(tab_info[2]);
        tab_node[cpt - 1]->name = my_strdup(tab_info[0]);
        tab_node[cpt - 1]->next = NULL;
        tab_node[cpt - 1]->previous = NULL;
        tab_node[cpt - 1]->distance_end = -1;
        tab_node[cpt -1]->occupied = 0;
        tab_node[cpt -1]->name_robot = return_name_robots(amazed);
    }
    return 0;
}

static void fill_end_node(get_info_t *info, node_t **tab_node,
    amazed_t *amazed)
{
    for (int i = 0; info->cells[i] != NULL; i++) {
        if (check_if_plus_null_end(info, i, tab_node, amazed) == 1)
            return;
    }
}

void add_node_to_tab(get_info_t *info,
    node_t **tab_node, amazed_t *amazed)
{
    fill_start_node(info, tab_node, amazed);
    fill_end_node(info, tab_node, amazed);
    for (int i = 0; tab_node[i] != NULL; i++) {
        if (tab_node[i]->name == NULL)
            fill_node(info, tab_node, amazed);
    }
}
