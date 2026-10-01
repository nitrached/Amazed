/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** create_node
*/
#include "amazed.h"
#include <stdlib.h>

static int add_node(node_t *new_node, list_t *maze,
    node_t **tab_node, get_info_t *info)
{
    for (int i = 0; tab_node[i]->name != NULL; i++) {
        if (my_strcmp(tab_node[i]->name, info->name_to_look) == 0) {
            new_node = tab_node[i];
            break;
        }
    }
    if (maze->start == NULL)
        maze->start = new_node;
    if (add_node_next(new_node, tab_node, info) == 42 ||
        add_node_prev(new_node, tab_node, info) == 42)
            return 42;
    maze->end = new_node;
    return 0;
}

static int create_node(node_t **tab_node, amazed_t *amazed, get_info_t *info)
{
    list_t *maze = amazed->maze;
    node_t *new_node = NULL;

    if (add_node(new_node, maze, tab_node, info) == 42)
        return 42;
    return 0;
}

int create_all_node(node_t **tab_node, get_info_t *info, amazed_t *amazed)
{
    for (int i = 0; tab_node[i] != NULL; i++) {
        info->name_to_look = my_strdup(tab_node[i]->name);
        if (create_node(tab_node, amazed, info) == 42)
            return 42;
    }
    return 0;
}
