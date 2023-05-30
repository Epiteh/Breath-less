/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** collectible_collision.c
*/

#include "rpg.h"

bool collectible_collision(rpg_t *rpg, sfRectangleShape *rect)
{
    sfFloatRect hitbox;

    hitbox = sfShape_getGlobalBounds((sfShape*)
        rect);
    if (sfFloatRect_contains(&hitbox, rpg->sprite.position.x + 20,
        rpg->sprite.position.y + 80)) {
        return (true);
    } else if (sfFloatRect_contains(&hitbox, rpg->sprite.position.x + 60,
        rpg->sprite.position.y + 80)) {
        return (true);
    }
    return (false);
}
