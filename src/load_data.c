/*
** EPITECH PROJECT, 2019
** load_game.c
** File description:
** load the data from radar files
*/

#include "basic.h"
#include "project.h"

int load_data(ui_t *ui, char *content, chain_t *plane_chain
, chain_t *tower_chain)
{
    ui->count.A = 0;
    ui->count.T = 0;
    for (int i = 0; content[i] != '\0'; i++) {
        if (content[i] == 'A') {
            load_flight_data(ui, content, plane_chain, i);
            ui->count.A += 1;
        }
        if (content[i] == 'T') {
            load_tower_data(ui, content, tower_chain, i);
            ui->count.T += 1;
        }
    }
    return (0);
}

void load_flight_data(ui_t *ui, char *buffer, chain_t *plane_chain, int i)
{
    char **word = malloc(sizeof(char *) * 10);
    plane_t *plane = malloc(sizeof(plane_t));

    increase_plane_list(plane_chain);
    plane_chain->plane->position = (sfVector2f){0.0f, 0.0f};
    plane_chain->plane->arrival = (sfVector2f){0.0f, 0.0f};
    for (int d = 0; d < 10; d++)
        word[d] = clean_alloc(sizeof(char) * 15);
    divide_buffer(buffer, word, i);
    set_plane(plane, word);
    insert_plane(plane_chain, plane, ui->count.A);
    for (int i = 0; i < 10; i++)
        free (word[i]);
    free(word);
}

void divide_buffer(char *buffer, char **word, int i)
{
    int count = 0;
    int k = 0;

    for (i += 2; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ') {
            word[count][k] = '\0';
            k = 0;
            count++;
            i += 1;
        }
        word[count][k] = buffer[i];
        k++;
    }
}

void load_tower_data(ui_t *ui, char *buffer, chain_t *tower_chain, int i)
{
    char **word = malloc(sizeof(char *) * 10);
    tower_t *tower = malloc(sizeof(tower_t));

    increase_tower_list(tower_chain);
    for (int d = 0; d < 10; d++)
        word[d] = clean_alloc(sizeof(char *) * 15);
    divide_buffer(buffer, word, i);
    set_tower(tower, word);
    insert_tower(tower_chain, tower, ui->count.T);
    for (int i = 0; i < 10; i++)
        free (word[i]);
    free(word);
}


