/*
** EPITECH PROJECT, 2019
** clock.c
** File description:
** main loop game clock
*/

#include "structure.h"
#include "project.h"

int set_clock(ui_t *ui)
{
    ui->loop.clock = sfClock_create();
    ui->run.clock = sfClock_create();
    ui->loop.delay = 1000;
    ui->run.delay = 0;
    return (0);
}