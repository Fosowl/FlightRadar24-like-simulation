/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "basic.h"
#include "project.h"
#include "project.h"

void bad_usage(void)
{
    my_putstr("./my_radar: bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
}

void print_usage(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("\t./my_radar [OPTIONS] path_to_script\n");
    my_putstr("\tpath_to_script The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("\t-h print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\t‘L’ key enable/disable hitboxes and areas.\n");
    my_putstr("\t‘S’ key enable/disable sprites.\n");
    my_putstr("\t ARROW KEYS : move across the map\n");
}

int main (int av, char **argc)
{
    char *content = NULL;
    chain_t *plane_chain = set_chain_list();
    chain_t *tower_chain = set_chain_list();
    ui_t ui;

    if (av != 2) {
        bad_usage();
        return (84);
    }
    if (compare(argc[1], "-h")) {
        print_usage();
        return (0);
    }
    content = load_file(argc[1]);
    if (content == NULL || check_content(content) == 1)
        return (84);
    if (set_game(&ui, content, plane_chain, tower_chain) == 1)
        return (84);
    return (0);
}

int check_content(char *content)
{
    for (int i = 0; content[i] != '\0'; i++) {
        if (char_in(content[i], " AT0123456789\n") == -1)
            return (1);
    }
    return (0);
}

int set_game(ui_t *ui, char *content
, chain_t *plane_chain, chain_t *tower_chain)
{
    if (content == NULL) {
        put_error("failed to open file !\n");
        return (84);
    }
    ui->camera = malloc(sizeof(camera_t));
    ui->tower = malloc(sizeof(render_t));
    ui->plane = malloc(sizeof(render_t));
    if (ui->camera == NULL || ui->tower == NULL || ui->plane == NULL)
        return (1);
    load_object(ui);
    set_clock(ui);
    initialize_plane(plane_chain);
    initialize_tower(tower_chain);
    load_data(ui, content, plane_chain, tower_chain);
    if (start_game(ui, plane_chain, tower_chain) == 1)
        return (84);
    return (0);
}