/*
** EPITECH PROJECT, 2023
** hitbox.c
** File description:
** hitbox player for collision
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "rpg.h"

sfRectangleShape *hitbox(rpg_t *rpg)
{
    float tickness = 2;
    sfVector2f origin = {-15, -7};
    sfVector2f position = rpg->sprite.position;

    sfRectangleShape *hitbox = sfRectangleShape_create();

    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(hitbox, sfWhite);
    sfRectangleShape_setOutlineThickness(hitbox, tickness);
    sfRectangleShape_setOrigin(hitbox, origin);
    sfRectangleShape_setPosition(hitbox, position);
    sfRectangleShape_setSize(hitbox, rpg->sprite.hitbox_size);

    return (hitbox);
}
