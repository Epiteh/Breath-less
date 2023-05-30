/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collision
*/

#include "rpg.h"

void map_tp_control_zone(rpg_t *rpg, sfColor color)
{
    if (is_same_color(color, (sfColor) {255, 16, 16, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 175, 591);
        rpg->sprite.position.x = 175;
        rpg->sprite.position.y = 591;
        if (rpg->mission.go_safe_place_done &&
            !rpg->mission.go_control_zone_done) {
            rpg->mission.go_control_zone = false;
            rpg->mission.do_control_fight = true;
            rpg->mission_text.is_writing = true;
            rpg->mission_text.letter_counter = 0;
            sfText_setPosition(rpg->mission_text.text,
                (sfVector2f) {1525 + 65, 410 + 8});
        }
        if (rpg->mission.do_control_fight_done &&
            !rpg->mission.go_control_zone_done) {
            rpg->mission.go_control_zone_done = true;
        }
        scene.scene = "control_zone";
    }
}

void reset_simple_room(rpg_t *rpg)
{
    if (rpg->mission.do_place_fight_done &&
        !rpg->mission.go_safe_place_done ) {
        rpg->mission.go_safe_place = false;
        rpg->mission.go_control_zone = true;
        rpg->mission_text.is_writing = true;
        rpg->mission_text.letter_counter = 0;
        sfText_setPosition(rpg->mission_text.text,
            (sfVector2f) {1525 + 30, 410 + 13});
    }
}

static void check_collision_left(rpg_t *rpg, sfImage *image, bool *is_moving)
{
    sfColor color = sfImage_getPixel(image, rpg->sprite.position.x + 10,
        rpg->sprite.position.y + 45);

    if (is_same_color(color, (sfColor) {0, 0, 0, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        *is_moving = false;
    }
    map_tp(rpg, color);
}

void wall_map_collision(rpg_t *rpg, sfImage *image)
{
    bool is_moving = true;
    sfColor color;

    check_collision_left(rpg, image, &is_moving);
    if (my_strcmp(scene.scene, "game") != 0) {
        return;
    }
    color = sfImage_getPixel(image, rpg->sprite.position.x + 35,
        rpg->sprite.position.y + 45);
    if (is_same_color(color, (sfColor) {0, 0, 0, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        is_moving = false;
    }
    if (is_moving) {
        rpg->tp.player_pos.x = rpg->sprite.position.x;
        rpg->tp.player_pos.y = rpg->sprite.position.y;
    }
    map_tp(rpg, color);
}
