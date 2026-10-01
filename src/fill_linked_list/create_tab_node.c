/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** add_node
*/
#include "amazed.h"
#include <stdio.h>
#include <stdlib.h>

static node_t **init_tab_node(get_info_t *info)
{
    node_t **tab = NULL;
    int i = 0;

    for (; info->cells_name[i] != NULL; i++);
    tab = malloc(sizeof(node_t *) * (i + 1));
    for (int j = 0; j < i; j++) {
        tab[j] = malloc(sizeof(node_t));
        tab[j]->next = NULL;
        tab[j]->previous = NULL;
        tab[j]->name = NULL;
    }
    tab[i] = NULL;
    return tab;
}

int check_coord(node_t **tab_node, int i)
{
    for (int cpt = 0; tab_node[cpt] != NULL; cpt++) {
        if (cpt == i)
            continue;
        if ((tab_node[i]->coordx == tab_node[cpt]->coordx
            && tab_node[i]->coordy == tab_node[cpt]->coordy))
            return 84;
    }
    return 0;
}

int check_tab_node(node_t **tab_node)
{
    for (int i = 0; tab_node[i] != NULL; i++) {
        if (tab_node[i]->name == NULL) {
            tab_node[i] = NULL;
            return 84;
        }
        if (check_coord(tab_node, i) == 84) {
            tab_node[i] = NULL;
            return 84;
        }
    }
    return 0;
}

static void check_complete_maze(node_t *node, node_t *head, get_info_t *info)
{
    if (node == NULL)
        return;
    for (int i = 0; node->previous[i] != NULL; i++) {
        if (node->previous[i]->name == head->name)
            info->can_complete++;
        check_complete_maze(node->previous[i], head, info);
    }
}

static void calcul_nb_node(node_t **tab_node, amazed_t *amazed)
{
    int nb = 0;

    for (; tab_node[nb] != NULL; nb++);
    amazed->maze->nb_nodes = nb;
}

int create_tab_node(amazed_t *amazed)
{
    get_info_t *info = innit_struct_info(amazed);
    node_t **tab_node = NULL;

    if (info == NULL)
        amazed->to_return = 84;
    tab_node = init_tab_node(info);
    add_node_to_tab(info, tab_node, amazed);
    calcul_nb_node(tab_node, amazed);
    if (check_tab_node(tab_node) == 84)
        amazed->to_return = 84;
    if (create_all_node(tab_node, info, amazed) == 42)
        amazed->to_return = 84;
    check_complete_maze(amazed->maze->end, amazed->maze->start, info);
    if (info->can_complete == 0)
        amazed->to_return = 2;
    print_parsing(info, amazed);
    return 0;
}
