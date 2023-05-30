/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** player's movement
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include "rpg.h"

bool move_down(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        rpg->sprite.sprite_path = my_strdup(rpg->sprite.down);
        rpg->sprite.position.y += 1;
        return (true);
    }
    return (false);
}

bool move_left(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        rpg->sprite.sprite_path = my_strdup(rpg->sprite.left);
        rpg->sprite.position.x -= 1;
        return (true);
    }
    return (false);
}

bool move_right(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rpg->sprite.sprite_path =
            my_strdup(rpg->sprite.right);
        rpg->sprite.position.x += 1;
        return (true);
    }
    return (false);
}

bool move_up(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        rpg->sprite.sprite_path = my_strdup(rpg->sprite.up);
        rpg->sprite.position.y -= 1;
        return (true);
    }
    return (false);
}

void move_player(rpg_t *rpg)
{
    if (move_down(rpg) || move_right(rpg) || move_up(rpg) || move_left(rpg)) {
        sfSprite_destroy(rpg->sprite.sprite);
        sfTexture_destroy(rpg->sprite.texture);
        rpg->sprite.texture = sfTexture_createFromFile(rpg->sprite.sprite_path,
            NULL);
        rpg->sprite.sprite = sfSprite_create();
        sfSprite_setTexture(rpg->sprite.sprite, rpg->sprite.texture, sfTrue);
        sfSprite_setTextureRect(rpg->sprite.sprite, rpg->sprite.rect);
        sfSprite_setScale(rpg->sprite.sprite, rpg->sprite.sprite_size);
        animation(rpg);
    } else {
        rpg->sprite.rect.left = 0;
        sfSprite_setTextureRect(rpg->sprite.sprite, rpg->sprite.rect);
        sfSprite_setScale(rpg->sprite.sprite, rpg->sprite.sprite_size);
    }
}
