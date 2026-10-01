/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** free_all
*/
#include "amazed.h"

void free_all(amazed_t *amazed)
{
    tab_free(amazed->tab);
}
