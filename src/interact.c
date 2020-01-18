/*
** EPITECH PROJECT, 2019
** interact.c
** File description:
** get user interaction
*/

#include "project.h"

void get_input(ui_t *ui)
{
    ui->interact.UP = 0;
    ui->interact.DOWN = 0;
    ui->interact.LEFT = 0;
    ui->interact.RIGHT = 0;
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue
    && ui->camera->relative.y > 0)
        ui->interact.UP = 1;
    else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue &&
    ui->camera->relative.y < 1024 * 3)
        ui->interact.DOWN = 1;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue &&
    ui->camera->relative.x >= -1)
        ui->interact.LEFT = 1;
    else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue &&
    ui->camera->relative.x < 2048 * 3)
        ui->interact.RIGHT = 1;
    update_board_input(ui);
}

void update_board_input(ui_t *ui)
{
    if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue &&
    ui->visibility.box == 0)
        ui->visibility.box = 1;
    else if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue
    && ui->visibility.box == 1)
        ui->visibility.box = 0;

    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue &&
    ui->visibility.fly == 0)
        ui->visibility.fly = 1;
    else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue
    && ui->visibility.fly == 1)
        ui->visibility.fly = 0;
}