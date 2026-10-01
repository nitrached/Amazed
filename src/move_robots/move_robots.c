/*
** EPITECH PROJECT, 2024
** a-maze-d_with_M_M
** File description:
** move_robots
*/
#include "amazed.h"
#include <stddef.h>

/* void print_robot_positions(node_t *node)
{
    if (node == NULL)
        return;
    my_printf("P%d-%s\n", node->name_robot[0], node->name);
    for (int i = 0; node->next[i] != NULL; i++) {
        print_robot_positions(node->next[i]);
    }
}

void move_all_node_forrward(node_t *node, int *robot_reached_end)
{
    if (node == NULL)
        return;
    for (int i = 0; node->name_robot[i] != NULL; i++) {
        robot_reached_end += 1;
    }
    for (int i = 0; node->previous[i] != NULL; i++) {
        if (node->previous[i]->occupied && node->previous[i]->distance_end >
        node->distance_end) {
            node->previous[i]->name_robot[0] = node->name_robot[0];
        }
    }
    for (int i = 0; node->previous[i] != NULL; i++) {
        move_all_node_forrward(node->previous[i], &robot_reached_end);
    }
}

int get_in_robot(amazed_t *amazed, int robot_in_maze)
{
    int *node_value = NULL;
    int nb_next = 0;
    int tmp;
    node_t *head = amazed->maze->start;

    for (; head->next[nb_next] != NULL; nb_next++);
    node_value = malloc(sizeof(int) * (nb_next));

    for (int i = 0; head->next[i] != NULL; i++)
        node_value[i] = head->next[i]->distance_end;

    tmp = head->next[0]->distance_end;
    for (int i = 0; head->next[i] != NULL; i++) {
        if (head->next[tmp]->distance_end > head->next[i]->distance_end)
    }
}

int move_robots(amazed_t *amazed)
{
    int robot_in_maze = 0;
    int robot_reached_end = 0;

    while (robot_reached_end < amazed->robot_nb) {
        move_all_node_forrward(amazed->maze->end, &robot_reached_end);
        if (robot_in_maze < amazed->robot_nb) {
            robot_in_maze = get_in_robot(amazed, robot_in_maze);
        }
        print_robot_positions(amazed->maze->start);
        if (robot_reached_end == amazed->robot_nb)
            break;
    }
    return 1;
} */

/* //if (node->previous[i]->visited)
        //    continue;
        //my_printf("NAME = [%s] [occupied = %d] [previous oqp = %d]
        [distance end = %d] [previous end = %d]\n", node->name,
        node->occupied, node->previous[i]->occupied, node->distance_end,
        node->previous[i]->distance_end); */

static int move_forr_cond(amazed_t *amazed, node_t *node, int *cpt, int i)
{
    if ((node->previous[i]->occupied
        && (!node->occupied || node == amazed->maze->end))
        && node->previous[i]->distance_end > node->distance_end) {
        node->name_robot[(*cpt)] = node->previous[i]->name_robot[0];
        node->occupied = true;
        node->previous[(*cpt)]->occupied = false;
        if (node->previous == NULL)
            my_printf(" ");
        my_printf("P%d-%s", node->name_robot[(*cpt)], node->name);
        amazed->rote = 1;
        if (node == amazed->maze->end) {
            (*cpt)++;
            return 0;
        } else
            return 1;
    }
    return 84;
}

static void move_all_node_forrward(node_t *node, int *robot_reached_end,
    amazed_t *amazed)
{
    int cpt = 0;

    if (node == NULL)
        return;
    node->visited = true;
    if (node == amazed->maze->end)
        for (int i = 0; node->name_robot[i] != '\0'; i++) {
            *robot_reached_end += 1;
            node->name_robot[i] = '\0';
            node->occupied = false;
        }
    for (int i = 0; node->previous[i] != NULL; i++) {
        if (move_forr_cond(amazed, node, &cpt, i) == 1)
            break;
    }
    for (int i = 0; node->previous[i] != NULL; i++) {
        move_all_node_forrward(node->previous[i], robot_reached_end, amazed);
    }
}

void cond_get_in(amazed_t *amazed, int tmp)
{
    if (amazed->rote)
        my_printf(" ");
    my_printf("P%d-%s", NEXT_ROBOT, NEXT_NAME);
    my_printf("\n");
    amazed->rote = 1;
    return;
}

static int get_in_robot(amazed_t *amazed, int robot_in_maze)
{
    int tmp = 0;
    node_t *head = amazed->maze->start;

    tmp = 0;
    for (int i = 0; head->next[i] != NULL; i++) {
        if (head->next[tmp]->occupied && !head->next[i]->occupied)
            tmp = i;
        if (head->next[tmp]->distance_end > head->next[i]->distance_end
            && !head->next[i]->occupied)
            tmp = i;
    }
    if (amazed->maze->start->next[tmp]->occupied)
        return robot_in_maze;
    robot_in_maze++;
    NEXT_ROBOT = robot_in_maze;
    amazed->maze->start->next[tmp]->occupied = true;
    cond_get_in(amazed, tmp);
    return robot_in_maze;
}

static void set_visited_false(node_t *node)
{
    if (node == NULL)
        return;
    node->visited = false;
    for (int i = 0; node->next[i] != NULL; i++) {
        set_visited_false(node->next[i]);
    }
}

int move_robots(amazed_t *amazed)
{
    int robot_in_maze = 0;
    int robot_reached_end = 0;

    amazed->rote = 0;
    set_visited_false(amazed->maze->start);
    my_printf("#moves\n");
    while (robot_reached_end < amazed->robot_nb) {
        move_all_node_forrward(amazed->maze->end, &robot_reached_end, amazed);
        if (robot_in_maze < amazed->robot_nb) {
            robot_in_maze = get_in_robot(amazed, robot_in_maze);
        }
        set_visited_false(amazed->maze->start);
        amazed->rote = 0;
    }
    my_printf("\n");
    return 1;
}
