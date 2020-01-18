/*
** EPITECH PROJECT, 2019
** structure.h
** File description:
** structure of my_radar project
*/

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Clock.h>

typedef struct render_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f offset;
    sfTexture *box_texture;
    sfSprite *box_sprite;
} render_t;

typedef struct camera_t
{
    sfVector2f relative;
    float offset_v;
    float offset_h;
} camera_t;

typedef struct visibility_t {
    int fly;
    int box;
} visibility_t;

typedef struct count_t {
    int A;
    int T;
} count_t;


typedef struct interaction_t {
    int UP;
    int DOWN;
    int LEFT;
    int RIGHT;
    int L;
    int S;
} interaction_t;

typedef struct watch_t {
    sfTime time;
    sfClock *clock;
    float delay;
} watch_t;

typedef struct ui_t {
    sfRenderWindow *window;
    sfVector2u size;
    sfEvent event;
    camera_t *camera;
    render_t background[4][4];
    count_t count;
    visibility_t visibility;
    render_t *tower;
    render_t *plane;
    interaction_t interact;
    watch_t loop;
    watch_t run;
} ui_t;

typedef struct plane_t {
    sfVector2f position;
    sfVector2f departure;
    sfVector2f arrival;
    int monitored;
    float speed;
    float angle;
    int delay;
    int landed;
} plane_t;

typedef struct tower_t {
    sfVector2f position;
    float radius;
} tower_t;

typedef struct chain_t {
    struct chain_t *back;
    struct chain_t *next;
    plane_t *plane;
    tower_t *tower;
    int count;
} chain_t;

typedef struct collide_t
{
    chain_t *chain;
} collide_t;

#endif /* !STRUCTURE_H_ */
