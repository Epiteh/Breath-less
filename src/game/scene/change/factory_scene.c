/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** factory_scene.c
*/

#include "rpg.h"

void change_factory_scene(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "factory") == 0) {
        display_factory_scene(rpg);
        display_render_texture(rpg);
        wall_factory_collision(rpg, rpg->factory.image);
        if (my_strcmp(scene.scene, "factory") == 0) {
            move_player(rpg);
            position(rpg);
        }
    }
    if (my_strcmp(scene.scene, "factory_basement") == 0) {
        display_factory_basement_scene(rpg);
        display_render_texture(rpg);
        wall_factory_basement_collision(rpg, rpg->factory_basement.image);
        if (my_strcmp(scene.scene, "factory_basement") == 0) {
            move_player(rpg);
            position(rpg);
        }
    }
}
