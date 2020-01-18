/*
** EPITECH PROJECT, 2019
** snake->c
** File description:
** function to move snake animation
*/

#include "project.h"

void rotate_sprite(sfSprite *sprite, float angle)
{
    float current_angle = 0.0f;
    float new_angle = 0.0f;

    current_angle = sfSprite_getRotation(sprite);
    if (angle > current_angle)
        new_angle = current_angle += 5;
    else if (angle < current_angle)
        new_angle = current_angle -= 5;
    sfSprite_setRotation(sprite, new_angle);
}

float move_sprite(sfVector2f *from, sfVector2f *to, float average_speed
, int delay)
{
    sfVector2f vector = (sfVector2f){0.0f, 0.0f};
    float angle = 0.0f;
    float distance = 100.0f;
    sfVector2f speed = (sfVector2f){0.0f, 0.0f};

    average_speed = average_speed * ((float)delay / 1000.0f);
    vector.x = to->x - from->x;
    vector.y = to->y - from->y;
    distance = sqrt(pow(vector.y, 2) + pow(vector.x, 2));
    if (distance >= 15.0f) {
        angle = atan2(vector.y, vector.x) * 57;
        speed.x = 2 * cos(angle) * average_speed;
        speed.y = 2 * sin(180 - (angle + 90)) * average_speed;
        from->y += speed.y;
        from->x += speed.x;
    }
    return (angle + 180);
}