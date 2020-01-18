/*
** EPITECH PROJECT, 2019
** measure_distance.c
** File description:
** measure distance between coordonate
*/

#include "project.h"

float distance(sfVector2f *from, sfVector2f *to)
{
    float distance = 0.0f;
    sfVector2f vector = (sfVector2f){0.0f, 0.0f};

    if (to->y >= from->y)
        vector.x = to->y - from->y;
    else if (to->y != from->y) {
        vector.y = from->y - to->y;
    }
    if (to->x >= from->x)
        vector.x = to->x - from->x;
    else if (from->x != from->x) {
        vector.x = from->x - to->x;
    }
    distance = sqrt((vector.y*vector.y) + (vector.x*vector.x));
    return (distance);
}