/*
** EPITECH PROJECT, 2024
** a-maze-d_with_M_M
** File description:
** find_all_path
*/
#include "my.h"
#include "amazed.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int test(node_t *prev, node_t *current, node_t *queue[], int tail)
{
    if (prev->distance_end == -1 || prev->distance_end >
        current->distance_end + 1) {
        prev->distance_end = current->distance_end + 1;
        queue[tail] = prev;
        tail++;
    }
    return tail;
}

void set_distance_from_end(amazed_t *amazed)
{
    node_t *queue[amazed->maze->nb_nodes];
    int head = 0;
    int tail = 0;
    node_t *current = NULL;
    node_t *prev = NULL;

    queue[tail] = amazed->maze->end;
    tail++;
    amazed->maze->end->distance_end = 0;
    while (head != tail) {
        current = queue[head];
        head++;
        for (int i = 0; current->previous[i] != NULL; i++) {
            prev = current->previous[i];
            tail = test(prev, current, queue, tail);
        }
    }
}
