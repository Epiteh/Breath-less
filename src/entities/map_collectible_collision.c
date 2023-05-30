/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** map_collectible_collision.c
*/

#include "rpg.h"

bool map_collectible_collision(rpg_t *rpg, sfRectangleShape *rect)
{
    sfFloatRect hitbox;

    hitbox = sfShape_getGlobalBounds((sfShape*)
        rect);
    if (sfFloatRect_contains(&hitbox, rpg->sprite.position.x + 10,
        rpg->sprite.position.y + 45)) {
        return (true);
    } else if (sfFloatRect_contains(&hitbox, rpg->sprite.position.x + 35,
        rpg->sprite.position.y + 45)) {
        return (true);
    }
    return (false);
}
