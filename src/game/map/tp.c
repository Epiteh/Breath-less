/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** map
*/

#include "rpg.h"

void map_tp_simple_room(rpg_t *rpg, sfColor color)
{
    map_tp_control_zone(rpg, color);
    if (is_same_color(color, (sfColor) {255, 6, 6, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 102, 652);
        rpg->sprite.position.x = 102;
        rpg->sprite.position.y = 652;
        reset_simple_room(rpg);
        rpg->mission.go_safe_place_done = true;
        if (rpg->mission.do_control_fight_done &&
            rpg->mission.go_back_safe_place) {
            rpg->mission.go_back_safe_place = false;
            rpg->mission.go_back_safe_place_done = true;
        }
        scene.scene = "safe_place";
    }
}

void map_tp(rpg_t *rpg, sfColor color)
{
    if (is_same_color(color, (sfColor) {255, 2, 2, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 643, 292);
        rpg->sprite.position.x = 643;
        rpg->sprite.position.y = 292;
        scene.scene = "factory";
    }
    if (is_same_color(color, (sfColor) {255, 9, 9, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 464, 520);
        rpg->sprite.position.x = 464;
        rpg->sprite.position.y = 520;
        scene.scene = "logos_entrance";
    }
    map_tp_simple_room(rpg, color);
}
