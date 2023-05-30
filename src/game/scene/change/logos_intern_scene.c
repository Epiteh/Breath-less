/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** logos_intern_scene.c
*/

#include "rpg.h"

void change_logos_intern_scene(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "logos_machine") == 0) {
        display_logos_machine_scene(rpg);
        display_render_texture(rpg);
        wall_logos_machine_collision(rpg, rpg->logos_machine.image);
        if (my_strcmp(scene.scene, "logos_machine") == 0) {
            move_player(rpg);
            position(rpg);
        }
    }
    if (my_strcmp(scene.scene, "logos_office") == 0) {
        display_logos_office_scene(rpg);
        display_render_texture(rpg);
        wall_logos_office_collision(rpg, rpg->logos_office.image);
        if (my_strcmp(scene.scene, "logos_office") == 0) {
            move_player(rpg);
            position(rpg);
        }
    }
}
