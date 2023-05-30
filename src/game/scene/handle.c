/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** handle
*/

#include "rpg.h"
#include <stdio.h>

static void display_menu(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "char_creator") == 0) {
        display_char_menu(rpg);
    }
}

void handle_scene(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "loader") == 0) {
        display_loader(rpg);
    }
    if (my_strcmp(scene.scene, "start") == 0) {
        sfMusic_play(rpg->start.music);
        rpg->start.is_start = true;
        background(rpg);
        display_start_menu(rpg);
        if (rpg->save.is_load) {
            display_save_menu(rpg);
        }
    } else {
        rpg->start.is_start = false;
    }
    display_menu(rpg);
}
