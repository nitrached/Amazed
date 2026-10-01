/*
** EPITECH PROJECT, 2024
** starting_project
** File description:
** buble_sort
*/
#include <stdio.h>
#include <string.h>
#include "../include/my.h"

static void swap(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}

static void condition(char **tab, int j)
{
    if (my_strcasecmp(tab[j], tab[j + 1]) > 0)
        swap(&tab[j], &tab[j + 1]);
        return;
    return;
}

void sort_bubble(char **tab)
{
    int n = 0;

    while (tab[n] != NULL)
        n++;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            condition(tab, j);
        }
    }
}
