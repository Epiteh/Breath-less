/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collision
*/

#include "rpg.h"

static void bar_tp(rpg_t *rpg, sfColor color)
{
    if (is_same_color(color, (sfColor) {255, 1, 0, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 395, 125);
        rpg->sprite.position.x = 395;
        rpg->sprite.position.y = 125;
        rpg->mission.escape_bar = false;
        rpg->mission.catch_knife = true;
        rpg->mission_text.is_writing = true;
        rpg->mission_text.letter_counter = 0;
        sfText_setPosition(rpg->mission_text.text,
            (sfVector2f) {1525 + 45, 410 + 13});
        scene.scene = "game";
    }
}

static void check_collision_left(rpg_t *rpg, sfImage *image, bool *is_moving)
{
    sfColor color = sfImage_getPixel(image, rpg->sprite.position.x + 20,
        rpg->sprite.position.y + 80);

    if (is_same_color(color, (sfColor) {0, 0, 0, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        *is_moving = false;
    }
    bar_tp(rpg, color);
}

void wall_bar_collision(rpg_t *rpg, sfImage *image)
{
    bool is_moving = true;
    sfColor color;

    check_collision_left(rpg, image, &is_moving);
    if (my_strcmp(scene.scene, "bar") != 0)
        return;
    color = sfImage_getPixel(image, rpg->sprite.position.x + 60,
        rpg->sprite.position.y + 80);

    if (is_same_color(color, (sfColor) {0, 0, 0, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        is_moving = false;
    }
    if (is_moving) {
        rpg->tp.player_pos.x = rpg->sprite.position.x;
        rpg->tp.player_pos.y = rpg->sprite.position.y;
    }
    bar_tp(rpg, color);
}
