/*
** EPITECH PROJECT, 2019
** tower.c
** File description:
** tower render and movement
*/

#include "project.h"
#include "project.h"

void move_tower(ui_t *ui, chain_t *tower_chain)
{
    chain_t *copy = tower_chain;

    while (copy->next != tower_chain) {
        if (ui->interact.UP == 1)
            copy->tower->position.y += 10.0f;
        else if (ui->interact.DOWN == 1)
            copy->tower->position.y += -10.0f;
        if (ui->interact.LEFT == 1)
            copy->tower->position.x += 10.0f;
        else if (ui->interact.RIGHT == 1)
            copy->tower->position.x += -10.0f;
        copy = copy->next;
    }
}

int draw_tower(ui_t *ui, chain_t *tower_chain)
{
    chain_t *copy = tower_chain;
    sfColor color = (sfColor){rand() % 100, 220, 40, 70};

    while (copy->next != tower_chain) {
        sfSprite_setPosition(ui->tower->sprite, copy->tower->position);
        sfRenderWindow_drawSprite(ui->window, ui->tower->sprite, NULL);
        my_draw_circle_pit(copy->tower->position, color
        , copy->tower->radius, ui->window);
        copy = copy->next;
    }
    return (0);
}