/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** single_scene.c
*/

#include "rpg.h"

void change_single_scene(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "safe_place") == 0) {
        display_safe_place_scene(rpg);
        manage_safe_place_npc(rpg);
        display_render_texture(rpg);
        wall_safe_place_collision(rpg, rpg->safe_place.image);
        if (my_strcmp(scene.scene, "safe_place") == 0) {
            move_player(rpg);
            position(rpg);
        }
    }
    if (my_strcmp(scene.scene, "logos_entrance") == 0) {
        display_logos_entrance_scene(rpg);
        display_render_texture(rpg);
        wall_logos_entrance_collision(rpg, rpg->logos_entrance.image);
        if (my_strcmp(scene.scene, "logos_entrance") == 0) {
            move_player(rpg);
            position(rpg);
        }
    }
}
