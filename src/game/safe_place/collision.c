/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collision
*/

#include "rpg.h"

static void safe_place_tp(rpg_t *rpg, sfColor color)
{
    if (is_same_color(color, (sfColor) {255, 5, 5, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 1755, 1352);
        rpg->sprite.position.x = 1755;
        rpg->sprite.position.y = 1352;
        rpg->hud.player_pos = (sfVector2f) {2175 - 1655, 1352};
        scene.scene = "game";
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
    safe_place_tp(rpg, color);
}

void wall_safe_place_collision(rpg_t *rpg, sfImage *image)
{
    bool is_moving = true;
    sfColor color;

    check_collision_left(rpg, image, &is_moving);
    if (my_strcmp(scene.scene, "safe_place") != 0)
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
    safe_place_tp(rpg, color);
}
