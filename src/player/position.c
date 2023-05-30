/*
** EPITECH PROJECT, 2023
** sprite.c
** File description:
** Creation of first player
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "rpg.h"
#include <stdio.h>

void position(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->sprite.sprite, rpg->sprite.position);
}
