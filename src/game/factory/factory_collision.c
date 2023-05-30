/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collision
*/

#include "rpg.h"

static void factory_tp(rpg_t *rpg, sfColor color)
{
    if (is_same_color(color, (sfColor) {255, 8, 8, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 830, 303);
        rpg->sprite.position.x = 830;
        rpg->sprite.position.y = 303;
        scene.scene = "game";
    }
    if (is_same_color(color, (sfColor) {255, 7, 7, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 1223, 220);
        rpg->sprite.position.x = 1223;
        rpg->sprite.position.y = 220;
        scene.scene = "factory_basement";
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
    factory_tp(rpg, color);
}

void wall_factory_collision(rpg_t *rpg, sfImage *image)
{
    bool is_moving = true;
    sfColor color;

    check_collision_left(rpg, image, &is_moving);
    if (my_strcmp(scene.scene, "factory") != 0)
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
    factory_tp(rpg, color);
}
