/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** second
*/

#include "rpg.h"

static void loader_image_close_change(rpg_t *rpg, sfColor fadeColor)
{
    fadeColor.a = rpg->loader.alpha;
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->loader.sprite[rpg->loader.time.y].sprite, NULL);
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->loader.rect[0].rect, NULL);
    sfRectangleShape_setFillColor(rpg->loader.rect[0].rect, fadeColor);
}

static void loader_image_close(rpg_t *rpg)
{
    if (sfTime_asMilliseconds(rpg->loader.clock.time) >=
        rpg->loader.time.close_start_time &&
            sfTime_asMilliseconds(rpg->loader.clock.time) <
                rpg->loader.time.close_end_time) {
        rpg->loader.alpha =
            (sfUint8)((sfTime_asMilliseconds(rpg->loader.clock.time)
                - 22500) * 255 / 7500);
        sfColor fadeColor =
            sfRectangleShape_getFillColor(rpg->loader.rect[0].rect);
        loader_image_close_change(rpg, fadeColor);
    }
}

static void loader_image_open_change(rpg_t *rpg, sfColor fadeColor)
{
    fadeColor.a = rpg->loader.alpha;
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->loader.sprite[rpg->loader.time.y].sprite, NULL);
    sfRectangleShape_setFillColor(rpg->loader.rect[0].rect, fadeColor);
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->loader.rect[0].rect, NULL);
}

void loader_image_open(rpg_t *rpg)
{
    if (sfTime_asMilliseconds(rpg->loader.clock.time) >=
        rpg->loader.time.open_start_time &&
            sfTime_asMilliseconds(rpg->loader.clock.time) <
                rpg->loader.time.open_end_time) {
        rpg->loader.alpha =
            (sfUint8)((7500 -
                sfTime_asMilliseconds(rpg->loader.clock.time) - 7500)
                    * 255 / 7500);
        sfColor fadeColor =
            sfRectangleShape_getFillColor(rpg->loader.rect[0].rect);
        loader_image_open_change(rpg, fadeColor);
    } else {
        loader_image_close(rpg);
    }
}
