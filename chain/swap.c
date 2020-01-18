/*
** EPITECH PROJECT, 2019
** swap.c
** File description:
** swap 2 element of a chain list
*/

#include "project.h"

int swap_to_front(chain_t *chain, chain_t *first)
{
    chain_t *temp = malloc(sizeof(chain_t));
    chain_t *copy = chain;

    if (chain == NULL || temp == NULL || copy == NULL)
        return (1);
    temp = copy;
    while (copy->next != first)
        copy = copy->next;
    copy->next = temp;
    temp->back = copy->back;
    free (temp);
    return (0);
}

int swap_to_back(chain_t *chain)
{
    chain->back = chain->next;
    chain->next->back = chain->back;
    return (0);
}