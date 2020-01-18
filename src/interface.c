/*
** EPITECH PROJECT, 2019
** interface.c
** File description:
** interface and background
*/

#include "basic.h"
#include "project.h"

int draw_interface(ui_t *ui)
{
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            sfSprite_setPosition(ui->background[i][k].sprite
            , ui->background[i][k].position);
            sfRenderWindow_drawSprite(ui->window
            , ui->background[i][k].sprite, NULL);
        }
    }
    return (0);
}
