/*
** EPITECH PROJECT, 2019
** pop.c
** File description:
** pop using chainlist
*/

#include "project.h"
#include <stdlib.h>

int remove_chain_list(chain_t *chain, int index)
{
    chain_t *temporary = set_chain_list();
    int i;

    if (chain == NULL)
        return (1);
    for (i = 0; i < index; i++) {
        if (chain == NULL)
            return (1);
        temporary = chain;
        chain = chain->next;
    }
    temporary->next = chain->next;
    chain->back = temporary;
    return (0);
}