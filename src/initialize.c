/*
** EPITECH PROJECT, 2019
** initialize.c
** File description:
** initialize plane and tower into a chain list
*/

#include "project.h"
#include "basic.h"
#include <stdio.h>

void initialize_ui(ui_t *ui)
{
    ui->size = (sfVector2u){1920, 1080};
    ui->camera->relative = (sfVector2f){0, 0};
    ui->camera->offset_h = ui->size.x / 2;
    ui->camera->offset_v = ui->size.y / 2;
    ui->visibility.fly = 1;
    ui->visibility.box = 1;
}

int load_object(ui_t *ui)
{
    ui->tower->texture = sfTexture_createFromFile("assets/tower.png", NULL);
    ui->plane->texture = sfTexture_createFromFile("assets/plane.png", NULL);
    ui->plane->box_texture = sfTexture_createFromFile("assets/box.png", NULL);
    if (ui->tower->texture == NULL || ui->plane->texture == NULL
    || ui->plane->box_texture == NULL)
        return (1);
    ui->tower->sprite = sfSprite_create();
    ui->plane->sprite = sfSprite_create();
    ui->plane->box_sprite = sfSprite_create();
    sfSprite_setTexture(ui->plane->sprite, ui->plane->texture, sfFalse);
    sfSprite_setTexture(ui->tower->sprite, ui->tower->texture, sfFalse);
    sfSprite_setTexture(ui->plane->box_sprite, ui->plane->box_texture, sfFalse);
    if (ui->tower->sprite == NULL || ui->plane->sprite == NULL) {
        put_error("memory allocation failure !\n");
        return (1);
    }
    sfSprite_setOrigin(ui->tower->sprite, (sfVector2f){0, 25});
    sfSprite_setOrigin(ui->plane->sprite, (sfVector2f){10, 10});
    sfSprite_setOrigin(ui->plane->box_sprite, (sfVector2f){10, 10});
    return (0);
}

int initialize_plane(chain_t *plane_chain)
{
    chain_t *copy = plane_chain;

    while (copy->next != plane_chain) {
        copy->plane->angle = 0.0f;
        copy->plane->monitored = 0;
        copy->plane->landed = 0;
        copy->plane->departure = (sfVector2f){0.0f, 0.0f};
        copy->plane->arrival = (sfVector2f){0.0f, 0.0f};
        copy->plane->position = (sfVector2f){0.0f, 0.0f};
        copy = copy->next;
    }
    return (0);
}

int initialize_tower(chain_t *tower_chain)
{
    chain_t *copy = tower_chain;

    while (copy->next != tower_chain) {
        copy->tower->radius = 0.0f;
        copy = copy->next;
    }
    return (0);
}