/*
** EPITECH PROJECT, 2019
** camera.c
** File description:
** move the map and object relative to camera dislacement
*/

#include "project.h"
#include "basic.h"

int move_camera (ui_t *ui)
{
    sfVector2f movement = (sfVector2f){0.0f, 0.0f};

    if (ui->interact.UP == 1)
        movement.y = 10.0f;
    else if (ui->interact.DOWN == 1)
        movement.y = -10.0f;
    if (ui->interact.LEFT == 1)
        movement.x = 10.0f;
    else if (ui->interact.RIGHT == 1)
        movement.x = -10.0f;
    ui->camera->relative.x += movement.x * -1;
    ui->camera->relative.y += movement.y * -1;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            ui->background[i][k].position.x += movement.x;
            ui->background[i][k].position.y += movement.y;
        }
    }
    return (0);
};