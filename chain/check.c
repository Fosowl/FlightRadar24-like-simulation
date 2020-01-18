/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** compare 2 chainlist
*/

#include "project.h"

int chain_len(chain_t *chain)
{
    int len = 0;
    chain_t *copy = chain;

    while (copy->next != chain) {
        len++;
        copy = copy->next;
    }
    return (len);
}