/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** add_node_previous
*/
#include "amazed.h"
#include <stdlib.h>

static int last_for(node_t **tab_node,
    node_t *new_node, char *path_info)
{
    for (int cpt = 0; tab_node[cpt] != NULL; cpt++) {
        if (my_strcmp(path_info, tab_node[cpt]->name) == 0) {
            new_node->previous =
                my_linked_list_realloc(new_node->previous, tab_node[cpt]);
            return 0;
        }
    }
    return 0;
}

int add_node_prev(node_t *new_node, node_t **tab_node, get_info_t *info)
{
    char **path_info = NULL;

    new_node->previous = malloc(sizeof(node_t *));
    new_node->previous[0] = NULL;
    for (int i = 0; info->path[i] != NULL; i++) {
        if (my_strchr(info->path[i], '-') == NULL) {
            info->path[i] = NULL;
            return 42;
        }
        path_info = my_str_to_word_array(info->path[i], "-");
        if (my_strcmp(info->name_to_look, path_info[1]) == 0) {
            last_for(tab_node, new_node, path_info[0]);
        }
    }
    return 0;
}
