/*
** EPITECH PROJECT, 2019
** load_texture.c
** File description:
** load texture for radar
*/

#include "project.h"

int load_world_texture(ui_t *ui)
{
    ui->background[0][0].texture = sfTexture_createFromFile
    ("assets/row-1-col-1.jpg", NULL);
    ui->background[0][1].texture = sfTexture_createFromFile
    ("assets/row-1-col-2.jpg", NULL);
    ui->background[0][2].texture = sfTexture_createFromFile
    ("assets/row-1-col-3.jpg", NULL);
    ui->background[0][3].texture = sfTexture_createFromFile
    ("assets/row-1-col-4.jpg", NULL);
    ui->background[1][0].texture = sfTexture_createFromFile
    ("assets/row-2-col-1.jpg", NULL);
    ui->background[1][1].texture = sfTexture_createFromFile
    ("assets/row-2-col-2.jpg", NULL);
    ui->background[1][2].texture = sfTexture_createFromFile
    ("assets/row-2-col-3.jpg", NULL);
    ui->background[1][3].texture = sfTexture_createFromFile
    ("assets/row-2-col-4.jpg", NULL);
    ui->background[2][0].texture = sfTexture_createFromFile
    ("assets/row-3-col-1.jpg", NULL);
    return (0);
}

int load_world_texture_2(ui_t *ui)
{
    ui->background[2][1].texture = sfTexture_createFromFile
    ("assets/row-3-col-2.jpg", NULL);
    ui->background[2][2].texture = sfTexture_createFromFile
    ("assets/row-3-col-3.jpg", NULL);
    ui->background[2][3].texture = sfTexture_createFromFile
    ("assets/row-3-col-4.jpg", NULL);
    ui->background[3][0].texture = sfTexture_createFromFile
    ("assets/row-4-col-1.jpg", NULL);
    ui->background[3][1].texture = sfTexture_createFromFile
    ("assets/row-4-col-2.jpg", NULL);
    ui->background[3][2].texture = sfTexture_createFromFile
    ("assets/row-4-col-3.jpg", NULL);
    ui->background[3][3].texture = sfTexture_createFromFile
    ("assets/row-4-col-4.jpg", NULL);
    return (0);
}
