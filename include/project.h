/*
** EPITECH PROJECT, 2019
** project.h
** File description:
** project prototype and include
*/

#ifndef PROJECT_H_
#define PROJECT_H_

#include "structure.h"

// set.c

chain_t *set_chain_list(void);

// push.c

int increase_plane_list(chain_t *first);
int increase_tower_list(chain_t *first);
int insert_plane(chain_t *chain, plane_t *plane, int index);
int insert_tower(chain_t *chain, tower_t *tower, int index);
int loop_insert(chain_t *chain, int index);

// aircraft.c

void move_plane(ui_t *ui, chain_t *plane_chain);
void move_plane_2(ui_t *ui, chain_t *copy);
void draw_plane(ui_t *ui, chain_t *plane_chain
, collide_t **sector);

// camera.c

int move_camera (ui_t *ui);

// clock.c

int set_clock(ui_t *ui);

// drawing.c

void my_draw_circle_pit(sfVector2f position, sfColor color
, float radius, sfRenderWindow *window);

// game.c

int load_image(ui_t *ui);
int start_game(ui_t *ui, chain_t *plane_chain, chain_t *tower_chain);
int set_background(ui_t *ui);
int looping(ui_t *ui, chain_t *plane_chain, chain_t *tower_chain
, collide_t **sector);

// initialize.c

void initialize_ui(ui_t *ui);
int load_object(ui_t *ui);
int initialize_plane(chain_t *plane_chain);
int initialize_tower(chain_t *tower_chain);

// interact.c

void get_input(ui_t *ui);
void update_board_input(ui_t *ui);

// interface.c

int draw_interface(ui_t *ui);

// load_data.c

int load_data(ui_t *ui, char *content, chain_t *plane_chain
, chain_t *tower_chain);
void load_flight_data(ui_t *ui, char *buffer, chain_t *plane_chain, int i);
void divide_buffer(char *buffer, char **word, int i);
void load_tower_data(ui_t *ui, char *buffer, chain_t *tower_chain, int i);

// load_texture.c

int load_world_texture(ui_t *ui);
int load_world_texture_2(ui_t *ui);

// main.c

int check_content(char *content);
int set_game(ui_t *ui, char *content
, chain_t *plane_chain, chain_t *tower_chain);

// measure_distance.c

float distance(sfVector2f *from, sfVector2f *to);

// move_sprite.c

void rotate_sprite(sfSprite *sprite, float angle);
float move_sprite(sfVector2f *from, sfVector2f *to, float average_speed
, int delay);

// set_data.c

void set_tower(tower_t *tower, char **word);
void set_plane(plane_t *plane, char **word);
void move_tower(ui_t *ui, chain_t *tower_chain);
int draw_tower(ui_t *ui, chain_t *tower_chain);

#endif /* !PROJECT_H_ */
