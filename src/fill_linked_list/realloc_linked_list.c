/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** realloc_linked_list
*/
#include "amazed.h"
#include <stdlib.h>

node_t **my_linked_list_realloc(node_t **old_tab, node_t *lign_to_add)
{
    int nbr_lign = 0;
    int new_nbr_lign = 0;
    int i = 0;
    node_t **new_tab;

    while (old_tab[nbr_lign] != NULL) {
        nbr_lign++;
    }
    new_nbr_lign += nbr_lign + 1;
    new_tab = malloc(sizeof(node_t *) * (new_nbr_lign + 1));
    while (i < nbr_lign) {
        new_tab[i] = old_tab[i];
        i++;
    }
    new_tab[new_nbr_lign - 1] = lign_to_add;
    new_tab[new_nbr_lign] = NULL;
    free(old_tab);
    return new_tab;
}
