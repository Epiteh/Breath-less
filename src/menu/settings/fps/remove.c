/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** remove
*/

#include "rpg.h"

void init_remove_fps(rpg_t *rpg)
{
    rpg->settings.sprite[2].texture =
        sfTexture_createFromFile("assets/menu/settings/left_arrow.png", NULL);
    rpg->settings.sprite[2].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->settings.sprite[2].sprite,
        rpg->settings.sprite[2].texture, sfTrue);
    sfSprite_setPosition(rpg->settings.sprite[2].sprite,
        (sfVector2f){1150, 255});
    sfSprite_setScale(rpg->settings.sprite[2].sprite,
        (sfVector2f){0.11, 0.11});
    sfSprite_setColor(rpg->settings.sprite[2].sprite,
        (sfColor){0, 0, 0, 255});
}

void remove_fps_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->settings.sprite[2].sprite, NULL);
}

void remove_fps_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->settings.sprite[2].sprite);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window.window,
        sfMouse_getPositionRenderWindow(rpg->window.window), NULL);
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        if (rpg->fps.fps == 0) {
            rpg->fps.fps = 0;
            my_itoa(rpg->fps.fps, rpg->fps.str);
            sfText_setString(rpg->settings.txt[0].text,
                rpg->fps.str);
            return;
        }
        rpg->fps.fps -= 1;
        my_itoa(rpg->fps.fps, rpg->fps.str);
        sfText_setString(rpg->settings.txt[0].text,
            rpg->fps.str);
        sfSound_play(rpg->settings.click);
    }
}
