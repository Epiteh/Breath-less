/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** add
*/

#include "rpg.h"
#include "stdio.h"

void init_add_fps(rpg_t *rpg)
{
    rpg->settings.sprite[1].texture =
        sfTexture_createFromFile("assets/menu/2.png", NULL);
    rpg->settings.sprite[1].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->settings.sprite[1].sprite,
        rpg->settings.sprite[1].texture, sfTrue);
    sfSprite_setPosition(rpg->settings.sprite[1].sprite,
        (sfVector2f){1275, 255});
    sfSprite_setScale(rpg->settings.sprite[1].sprite,
        (sfVector2f){0.11, 0.11});
    sfSprite_setColor(rpg->settings.sprite[1].sprite,
        (sfColor){0, 0, 0, 255});
}

void add_fps_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->settings.sprite[1].sprite, NULL);
}

void add_fps_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->settings.sprite[1].sprite);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window.window,
        sfMouse_getPositionRenderWindow(rpg->window.window), NULL);
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        rpg->fps.fps += 1;
        my_itoa(rpg->fps.fps, rpg->fps.str);
        sfText_setString(rpg->settings.txt[0].text,
            rpg->fps.str);
        sfSound_play(rpg->settings.click);
    }
}
