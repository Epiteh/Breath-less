/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** other_scene.c
*/

#include "rpg.h"

void change_other_scene(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "control_zone") == 0) {
        display_control_zone_scene(rpg);
        manage_control_zone_npc(rpg);
        display_render_texture(rpg);
        wall_control_zone_collision(rpg, rpg->control_zone.image);
        if (my_strcmp(scene.scene, "control_zone") == 0) {
            move_player(rpg);
            position(rpg);
        }
    }
    change_single_scene(rpg);
    change_logos_intern_scene(rpg);
    change_factory_scene(rpg);
}
