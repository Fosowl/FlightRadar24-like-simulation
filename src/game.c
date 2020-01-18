/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** radar initialization
*/

#include "project.h"
#include "project.h"
#include "basic.h"

int load_image(ui_t *ui)
{
    load_world_texture(ui);
    load_world_texture_2(ui);
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            ui->background[i][k].sprite = sfSprite_create();
            sfSprite_setTexture(ui->background[i][k].sprite,
            ui->background[i][k].texture, sfFalse);
            if (ui->background[i][k].sprite == NULL)
                return (1);
            if (ui->background[i][k].texture == NULL)
                return (1);
        }
    }
    return (0);
}

int start_game(ui_t *ui, chain_t *plane_chain, chain_t *tower_chain)
{
    collide_t **area;

    initialize_ui(ui);
    sfVideoMode mode = {ui->size.x, ui->size.y, 32};
    ui->window = sfRenderWindow_create(mode, "FlightRadar24"
    , sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(ui->window, 60);
    if (load_image(ui) == 1)
        return (1);
    set_background(ui);
    looping(ui, plane_chain, tower_chain, area);
    sfRenderWindow_close(ui->window);
    return (0);
}

int set_background(ui_t *ui)
{
    sfVector2f offset = (sfVector2f){0, 0};

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            ui->background[i][k].position.x = offset.x;
            ui->background[i][k].position.y = offset.y;
            sfSprite_setPosition(ui->background[i][k].sprite
            , ui->background[i][k].position);
            offset.x += 2048.0f;
        }
        offset.x = 0.0f;
        offset.y += 1024.0f;
    }
    return (0);
}

int looping(ui_t *ui, chain_t *plane_chain, chain_t *tower_chain
, collide_t **sector)
{
    while (sfRenderWindow_isOpen(ui->window)) {
        sfClock_restart(ui->loop.clock);
        while (sfRenderWindow_pollEvent(ui->window, &ui->event))
            if (ui->event.type == sfEvtClosed)
                return (2);
        get_input(ui);
        move_camera(ui);
        draw_interface (ui);
        move_tower(ui, tower_chain);
        move_plane(ui, plane_chain);
        draw_tower(ui, tower_chain);
        draw_plane(ui, plane_chain, sector);
        sfRenderWindow_display(ui->window);
        sfRenderWindow_clear(ui->window, sfBlack);
        ui->run.time = sfClock_getElapsedTime(ui->run.clock);
        ui->loop.time = sfClock_getElapsedTime(ui->loop.clock);
        ui->loop.delay = sfTime_asMilliseconds(ui->loop.time);
        ui->run.delay = (float)sfTime_asMilliseconds(ui->run.time);
    }
}
