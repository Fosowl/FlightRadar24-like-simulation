/*
** EPITECH PROJECT, 2019
** light_python.c
** File description:
** python fu like but in C
*/

#include "project.h"
#include "basic.h"

char *append(char *origin, char *added)
{
    char *fusioned = malloc(sizeof(char *) * (my_strlen(origin)
    +my_strlen(added)));
    int d = 0;

    if (fusioned == NULL)
        return (NULL);
    for (d = 0; origin[d] != '\0'; d++)
        fusioned[d] = origin[d];
    for (int i = 0; added[i] != '\0'; i++) {
        fusioned[d] = added[i];
        d++;
    }
    fusioned[d] = '\0';
    free (origin);
    return (fusioned);
}

char *pop(char *origin, char character)
{
    char *copy = NULL;
    int occurence = 0;
    int d = 0;

    for (int c = 0; origin[c]; c++) {
        if (origin[c] == character)
            occurence++;
    }
    copy = malloc(sizeof(char *) * (my_strlen(origin) - occurence) + 1);
    if (copy == NULL)
        return (NULL);
    for (int i = 0; origin[i] != '\0'; i++) {
        if (origin[i] == character)
            i++;
        copy[d] = origin[i];
        d++;
    }
    free (origin);
    return (copy);
}