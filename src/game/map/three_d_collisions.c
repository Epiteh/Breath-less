/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** three_d_collisions.c
*/

#include "rpg.h"

static void upper(rpg_t *rpg, sfImage *image, bool *is_moving)
{
    sfColor color = sfImage_getPixel(image, rpg->sprite.position.x + 10,
        rpg->sprite.position.y + 5);

    if (is_same_color(color, (sfColor) {1, 1, 1, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        *is_moving = false;
    }
    color = sfImage_getPixel(image, rpg->sprite.position.x + 35,
        rpg->sprite.position.y + 5);
    if (is_same_color(color, (sfColor) {1, 1, 1, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        *is_moving = false;
    }
}

static void check_collision_left(rpg_t *rpg, sfImage *image, bool *is_moving)
{
    sfColor color = sfImage_getPixel(image, rpg->sprite.position.x + 10,
        rpg->sprite.position.y + 45);

    if (is_same_color(color, (sfColor) {1, 1, 1, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        *is_moving = false;
    }
}

static void down(rpg_t *rpg, sfImage *image, bool *is_moving)
{
    sfColor color = sfImage_getPixel(image, rpg->sprite.position.x + 35,
        rpg->sprite.position.y + 45);

    check_collision_left(rpg, image, is_moving);
    if (is_same_color(color, (sfColor) {1, 1, 1, 255})) {
        rpg->sprite.position.x = rpg->tp.player_pos.x;
        rpg->sprite.position.y = rpg->tp.player_pos.y;
        *is_moving = false;
    }
}

void three_d_map_collision(rpg_t *rpg, sfImage *image, bool *is_moving)
{
    upper(rpg, image, is_moving);
    down(rpg, image, is_moving);
}
