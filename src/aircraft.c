/*
** EPITECH PROJECT, 2019
** aircraft.c
** File description:
** aircraft render and movement
*/

#include "project.h"
#include "structure.h"

void move_plane(ui_t *ui, chain_t *plane_chain)
{
    chain_t *copy = plane_chain;
    float angle = 0.0f;

    while (copy->next != plane_chain) {
        if (ui->interact.UP == 1) {
            copy->plane->position.y += 10.0f;
            copy->plane->arrival.y += 10.0f;
        } else if (ui->interact.DOWN == 1) {
            copy->plane->position.y -= 10.0f;
            copy->plane->arrival.y -= 10.0f;
        }
        move_plane_2(ui, copy);
        if (ui->run.delay / 1000 < (float)copy->plane->delay) {
            copy = copy->next;
            continue;
        }
        if (distance(&copy->plane->position, &copy->plane->arrival) > 15.0f)
            angle = move_sprite(&copy->plane->position, &copy->plane->arrival
            , copy->plane->speed, ui->loop.delay);
        rotate_sprite(ui->plane->sprite, angle);
        copy = copy->next;
    }
}

void move_plane_2(ui_t *ui, chain_t *copy)
{
    if (ui->interact.RIGHT == 1) {
        copy->plane->position.x -= 10.0f;
        copy->plane->arrival.x -= 10.0f;
    }
    else if (ui->interact.LEFT == 1) {
        copy->plane->position.x += 10.0f;
        copy->plane->arrival.x += 10.0f;
    }
}

void draw_plane(ui_t *ui, chain_t *plane_chain
, collide_t **area)
{
    chain_t *copy = plane_chain;

    while (copy->next != plane_chain) {
        if (ui->run.delay / 1000 < (float)copy->plane->delay) {
            copy = copy->next;
            continue;
        }
        sfSprite_setPosition(ui->plane->sprite
        , copy->plane->position);
        sfSprite_setPosition(ui->plane->box_sprite, copy->plane->position);
        if (ui->visibility.fly == 1)
            sfRenderWindow_drawSprite(ui->window, ui->plane->sprite, NULL);
        if (ui->visibility.box == 1)
            sfRenderWindow_drawSprite(ui->window, ui->plane->box_sprite, NULL);
        copy = copy->next;
    }
}

