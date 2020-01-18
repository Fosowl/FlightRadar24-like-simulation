/*
** EPITECH PROJECT, 2019
** push.c
** File description:
** push using chain list
*/

#include "project.h"
#include "project.h"

int increase_plane_list(chain_t *first)
{
    chain_t *new = set_chain_list();
    chain_t *chain = first;

    while (chain->next != first) {
        if (chain == NULL)
            return (84);
        chain = chain->next;
    }
    chain->plane = malloc(sizeof(plane_t));
    chain->tower = NULL;
    chain->next = new;
    new->back = chain;
    new->next = first;
    first->back = new;
    return (0);
}

int increase_tower_list(chain_t *first)
{
    chain_t *new = set_chain_list();
    chain_t *chain = first;

    while (chain->next != first) {
        if (chain == NULL)
            return (84);
        chain = chain->next;
    }
    chain->plane = NULL;
    chain->tower = malloc(sizeof(tower_t));
    chain->next = new;
    new->back = chain;
    new->next = first;
    first->back = new;
    return (0);
}

int insert_plane(chain_t *chain, plane_t *plane, int index)
{
    chain_t *copy = chain;

    for (int i = 0; i < index - 1; i++) {
        if (copy->next == chain || copy->next == NULL)
            return (1);
        copy = copy->next;
    }
    copy->plane = plane;
    return (0);
}

int insert_tower(chain_t *chain, tower_t *tower, int index)
{
    chain_t *copy = chain;

    for (int i = 0; i < index; i++) {
        if (copy->next == chain || copy->next == NULL)
            return (1);
        copy = copy->next;
    }
    copy->tower = tower;
    return (0);
}

int loop_insert(chain_t *chain, int index)
{
    for (int i = 0; i < index; i++) {
        if (chain == NULL)
            return (84);
        chain = chain->next;
    }
    return (0);
}
