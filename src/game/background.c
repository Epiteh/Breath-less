/*
** EPITECH PROJECT, 2023
** Epiteh-Engine
** File description:
** background
*/

#include "rpg.h"

void background(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->background.sprite, NULL);
}
