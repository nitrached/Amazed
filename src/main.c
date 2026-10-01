/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** main
*/
#include "my.h"
#include "amazed.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    amazed_t *amazed = innit_struct();

    if (argc != 1) {
        my_printf("Usage: %s < <nom_du_fichier>\n", argv[0]);
        return 84;
    }
    if (amazed == NULL)
        return 84;
    create_tab_node(amazed);
    if (amazed->to_return != 0)
        return 84;
    set_distance_from_end(amazed);
    move_robots(amazed);
    free_all(amazed);
    return 0;
}
