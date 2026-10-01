/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** fill_node
*/
#include "amazed.h"
#include <stdlib.h>

static int check_start_end(get_info_t *info, int i)
{
    if ((my_strcmp(info->cells[i], "##end") == 0
        || my_strcmp(info->cells[i], "##start") == 0)) {
        if (info->cells[i + 2] == NULL)
            return 2;
        i++;
        return 1;
    }
    return 0;
}

static int check_return(node_t **tab_node,
    char **tab_info, int cpt)
{
    if (tab_node[cpt]->name != NULL) {
        if (my_strcmp(tab_info[0], tab_node[cpt]->name) == 0)
            return 2;
        return 1;
    }
    return 0;
}

char *return_name_robots(amazed_t *amazed)
{
    char *name_robots = malloc(sizeof(char));

    name_robots[0] = '\0';
    for (int i = 0; i < amazed->robot_nb; i++) {
        name_robots = my_char_realloc(name_robots, '\0');
    }
    return name_robots;
}

static void put_data(get_info_t *info, node_t **tab_node,
    int i, amazed_t *amazed)
{
    char **tab_info = NULL;
    int check_break_continue = 0;

    tab_info = my_str_to_word_array(info->cells[i], " ");
    for (int cpt = 0; tab_node[cpt] != NULL; cpt++) {
        check_break_continue = check_return(tab_node, tab_info, cpt);
        if (check_break_continue == 2)
            break;
        if (check_break_continue == 1)
            continue;
        tab_node[cpt]->coordx = my_getnbr(tab_info[1]);
        tab_node[cpt]->coordy = my_getnbr(tab_info[2]);
        tab_node[cpt]->name = my_strdup(tab_info[0]);
        tab_node[cpt]->distance_end = -1;
        tab_node[cpt]->next = NULL;
        tab_node[cpt]->previous = NULL;
        tab_node[cpt]->occupied = 0;
        tab_node[cpt]->name_robot = return_name_robots(amazed);
        break;
    }
}

void fill_node(get_info_t *info, node_t **tab_node, amazed_t *amazed)
{
    int is_to_skip = 0;

    for (int i = 0; info->cells[i] != NULL; i++) {
        is_to_skip = check_start_end(info, i);
        if (is_to_skip == 2)
            break;
        if (is_to_skip == 1) {
            i++;
            continue;
        }
        put_data(info, tab_node, i, amazed);
    }
}
