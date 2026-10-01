/*
** EPITECH PROJECT, 2024
** a-maze-d_with_M_M
** File description:
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <stdbool.h>
    #include "my.h"
    #define TAB amazed->tab
    #define NEXT_ROBOT amazed->maze->start->next[tmp]->name_robot[0]
    #define NEXT_NAME amazed->maze->start->next[tmp]->name

typedef struct node_s {
    char *name;
    int coordx;
    int coordy;
    bool occupied;
    bool visited;
    int distance_end;
    char *name_robot;
    struct node_s **next; // tab of ptr on next
    struct node_s **previous;
} node_t;

typedef struct list_s {
    int nb_nodes;
    node_t *start;
    node_t *end;
} list_t;

typedef struct path_s {
    int nb_cells;
    char *cells;
} path_t;

typedef struct amazed_s {
    int robot_nb;
    int nb_path;
    path_t *all_path; // struct tab
    list_t *maze;
    char **tab;
    int to_return;
    int rote;
} amazed_t;

typedef struct get_info_s {
    char **cells_name;
    char **cells;
    char **path;
    char *name_to_look;
    int can_complete;
} get_info_t;

    /* PARSING */
amazed_t *innit_struct(void);
void free_all(amazed_t *amazed);
get_info_t *innit_struct_info(amazed_t *amazed);
char **innit_cells(amazed_t *amazed);
char **innit_path(amazed_t *amazed, char **tab_name, char **cells);
char **innit_cells_name(char **cell, amazed_t *amazed);
int create_tab_node(amazed_t *amazed);
int check_backslash_n(amazed_t *amazed, int i);
void print_parsing(get_info_t *info, amazed_t *amazed);
void fill_node(get_info_t *info, node_t **tab_node, amazed_t *amazed);
int create_all_node(node_t **tab_node, get_info_t *info, amazed_t *amazed);
int add_node_next(node_t *new_node,
    node_t **tab_node, get_info_t *info);
void print_all_node(node_t *node);
node_t **my_linked_list_realloc(node_t **old_tab, node_t *lign_to_add);
int add_node_prev(node_t *new_node, node_t **tab_node, get_info_t *info);
int check_multiple_start_end(char **cells);
int check_name_coord(char **cells);
int move_robots(amazed_t *amazed);
char *return_name_robots(amazed_t *amazed);
void add_node_to_tab(get_info_t *info,
    node_t **tab_node, amazed_t *amazed);


/* RESOLUTION */
void set_distance_from_end(amazed_t *amazed);
#endif /* !AMAZED_H_ */
