/*
** EPITECH PROJECT, 2019
** paint.c
** File description:
** function to print on screen with pixel
*/

#include "project.h"

void my_draw_circle_pit(sfVector2f position, sfColor color
, float radius, sfRenderWindow *window)
{
    sfCircleShape *circle;
    sfVector2f vector;
    int t = 0;

    circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, radius / 30);
    while (t < 360) {
        vector.x = radius * cos(t) + position.x;
        vector.y = radius * sin(t) + position.y;
        sfCircleShape_setPosition(circle, vector);
        sfRenderWindow_drawCircleShape(window, circle, NULL);
        t++;
    }
    sfCircleShape_destroy(circle);
}