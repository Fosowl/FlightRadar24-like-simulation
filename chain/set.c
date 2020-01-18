/*
** EPITECH PROJECT, 2019
** set.c
** File description:
** set element of the list
*/

#include "project.h"
#include <stdlib.h>

chain_t *set_chain_list(void)
{
    chain_t *chain = malloc(sizeof(chain_t));

    if (chain == NULL)
        return (NULL);
    chain->next = chain;
    chain->back = chain;
    return (chain);
}