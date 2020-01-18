/*
** EPITECH PROJECT, 2019
** set_data.c
** File description:
** set_data.c
*/

#include "project.h"
#include "basic.h"

void set_tower(tower_t *tower, char **word)
{
    tower->position.x = (float)my_atoi(word[0]);
    tower->position.y = (float)my_atoi(word[1]);
    tower->radius = ((float)my_atoi(word[2]) / 100) * 1920;
    if (tower->position.x >= 8192 || tower->position.x >= 4096) {
        my_putstr("warning : tower coordonate no exceed 8192 in");
        my_putstr(" width or 4096 in height\n");
    }
}

void set_plane(plane_t *plane, char **word)
{
    plane->position.x = (float)my_atoi(word[0]);
    plane->position.y = (float)my_atoi(word[1]);
    plane->departure.x = plane->position.x;
    plane->departure.y = plane->position.y;
    plane->arrival.x = (float)my_atoi(word[2]);
    plane->arrival.y = (float)my_atoi(word[3]);
    plane->speed = (float)my_atoi(word[4]);
    plane->delay = (float)my_atoi(word[5]);
    if (plane->position.x >= 8192 || plane->position.x >= 4096) {
        my_putstr("warning : plane coordonate should not exceed 8192 in");
        my_putstr("width or 4096 in height\n");
    }
}