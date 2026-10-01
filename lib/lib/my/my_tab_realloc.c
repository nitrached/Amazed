/*
** EPITECH PROJECT, 2023
** realloc
** File description:
** reallocate a tab in another tab
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char **my_realloc(char **old_tab, char *lign_to_add)
{
    int nbr_lign = 0;
    int new_nbr_lign = 0;
    int i = 0;
    char **new_tab;

    while (old_tab[nbr_lign] != NULL) {
        nbr_lign++;
    }
    new_nbr_lign += nbr_lign + 1;
    new_tab = malloc(sizeof(char *) * (new_nbr_lign + 1));
    while (i < nbr_lign) {
        new_tab[i] = old_tab[i];
        i++;
    }
    new_tab[new_nbr_lign - 1] = my_strdup(lign_to_add);
    new_tab[new_nbr_lign] = NULL;
    free(old_tab);
    return new_tab;
}
