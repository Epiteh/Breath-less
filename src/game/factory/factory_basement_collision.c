/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collision
*/

#include "rpg.h"

static void factory_basement_tp(rpg_t *rpg, sfColor color)
{
    if (is_same_color(color, (sfColor) {255, 3, 3, 255}) &&
        sfKeyboard_isKeyPressed(sfKeyY)) {
        init_tp_player(rpg, 1221, 262);
        rpg->sprite.position.x = 1221;
        rpg->sprite.position.y = 262;
        scene.scene = "factory";
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
    factory_basement_tp(rpg, color);
}

void wall_factory_basement_collision(rpg_t *rpg, sfImage *image)
{
    bool is_moving = true;
    sfColor color;

    check_collision_left(rpg, image, &is_moving);
    if (my_strcmp(scene.scene, "factory_basement") != 0)
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
    factory_basement_tp(rpg, color);
}
