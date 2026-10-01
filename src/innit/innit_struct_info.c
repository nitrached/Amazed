/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** innit_struct_info
*/
#include "amazed.h"
#include <stdio.h>
#include <stdlib.h>

static int check_cells(char **cells)
{
    if (check_multiple_start_end(cells) == 84)
        return 84;
    if (check_name_coord(cells) == 84)
        return 84;
    return 0;
}

get_info_t *innit_struct_info(amazed_t *amazed)
{
    get_info_t *info = malloc(sizeof(get_info_t));

    if (info == NULL)
        return NULL;
    info->can_complete = 0;
    info->cells = innit_cells(amazed);
    if (info->cells == NULL || check_cells(info->cells) == 84)
        amazed->to_return = 2;
    info->cells_name = innit_cells_name(info->cells, amazed);
    if (info->cells_name[0] == NULL)
        amazed->to_return = 2;
    info->path = innit_path(amazed, info->cells_name, info->cells);
    if (info->path[0] == NULL)
        amazed->to_return = 2;
    return info;
}
