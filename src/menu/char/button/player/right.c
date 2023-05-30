/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** right
*/

#include "rpg.h"
#include <stdio.h>

void init_right_player(rpg_t *rpg)
{
    rpg->creator.sprite[1].texture =
        sfTexture_createFromFile("assets/menu/char/right_arrow.png", NULL);
    rpg->creator.sprite[1].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->creator.sprite[1].sprite,
        rpg->creator.sprite[1].texture, sfTrue);
    sfSprite_setPosition(rpg->creator.sprite[1].sprite,
        (sfVector2f){638, 477});
    sfSprite_setScale(rpg->creator.sprite[1].sprite,
        (sfVector2f){0.34, 0.34});
    sfSprite_setColor(rpg->creator.sprite[1].sprite,
        (sfColor){0, 0, 0, 255});
}

void right_player_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->creator.sprite[1].sprite, NULL);
}

static void right_player_event_change_player(rpg_t *rpg)
{
    if (rpg->creator.index == 3) {
        rpg->creator.index += 1;
    } else if (rpg->creator.index == 4) {
        rpg->creator.index -= 1;
    }
}

void right_player_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->creator.sprite[1].sprite);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window.window,
        sfMouse_getPositionRenderWindow(rpg->window.window), NULL);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) &&
        rpg->window.event.type == sfEvtMouseButtonPressed) {
            right_player_event_change_player(rpg);
    }
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) &&
        rpg->window.event.type == sfEvtMouseMoved) {
            sfSprite_setScale(rpg->creator.sprite[1].sprite,
                (sfVector2f){0.35, 0.35});
    } else {
        sfSprite_setScale(rpg->creator.sprite[1].sprite,
            (sfVector2f){0.34, 0.34});
    }
}
