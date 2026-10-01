/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** print_parsing
*/
#include "amazed.h"
#include <stdio.h>

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%s\n", tab[i]);
    }
}

void print_parsing(get_info_t *info, amazed_t *amazed)
{
    if (amazed->robot_nb < 0)
        return;
    my_printf("#number_of_robots\n");
    my_printf("%d\n", amazed->robot_nb);
    my_printf("#rooms\n");
    print_tab(info->cells);
    if (amazed->to_return == 2)
        return;
    my_printf("#tunnels\n");
    print_tab(info->path);
}

void print_node(node_t *node)
{
    my_printf("name [%s] distance: %d\n", node->name, node->distance_end);
}

void print_all_node(node_t *node)
{
    if (node == NULL)
        return;
    my_printf("tail:");
    print_node(node);
    for (int i = 0; node->previous[i] != NULL; i++) {
        print_all_node(node->previous[i]);
    }
}
