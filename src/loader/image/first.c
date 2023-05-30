/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** first
*/

#include "rpg.h"

static void loader_first_image_open_change(rpg_t *rpg, sfColor fadeColor)
{
    fadeColor.a = rpg->loader.alpha;
    sfRectangleShape_setFillColor(rpg->loader.rect[0].rect, fadeColor);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->loader.sprite[0].sprite, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->loader.rect[0].rect, NULL);
}

void loader_first_image_open(rpg_t *rpg)
{
    rpg->loader.clock.time = sfClock_getElapsedTime(rpg->clock.clock);

    if (sfTime_asMilliseconds(rpg->loader.clock.time) <= 6000 &&
        sfTime_asMilliseconds(rpg->loader.clock.time) >= 0) {
            sfRenderWindow_clear(rpg->window.window, sfBlack);
            rpg->loader.alpha =
                (sfUint8)((6000 -
                    sfTime_asMilliseconds(rpg->loader.clock.time))
                        * 255 / 6000);
            sfColor fadeColor =
                sfRectangleShape_getFillColor(rpg->loader.rect[0].rect);
            loader_first_image_open_change(rpg, fadeColor);
    }
}
