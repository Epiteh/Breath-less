/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** how_to_play
*/

#include "rpg.h"
#include <stdbool.h>

void start_init_how_to_play_bg(rpg_t *rpg)
{
    rpg->start.sprite_menu[1].texture =
        sfTexture_createFromFile("assets/how_to_play.png", NULL);
    rpg->start.sprite_menu[1].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->start.sprite_menu[1].sprite,
        rpg->start.sprite_menu[1].texture, sfTrue);
    sfSprite_setPosition(rpg->start.sprite_menu[1].sprite,
        (sfVector2f){455, 853});
    sfSprite_setScale(rpg->start.sprite_menu[1].sprite,
        (sfVector2f){0.1, 0.1});
    sfSprite_setColor(rpg->start.sprite_menu[1].sprite,
        (sfColor){255, 255, 255, 255});
}

void init_start_how_to_play_img(rpg_t *rpg)
{
    rpg->start.sprite_menu[2].texture =
        sfTexture_createFromFile("assets/menu_how_to_play.png", NULL);
    rpg->start.sprite_menu[2].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->start.sprite_menu[2].sprite,
        rpg->start.sprite_menu[2].texture, sfTrue);
    sfSprite_setScale(rpg->start.sprite_menu[2].sprite,
        (sfVector2f){1.01, 0.95});
}

void start_how_to_play_view(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "start") == 0 ||
            rpg->menu.escape_menu == true) {
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->start.sprite_menu[1].sprite, NULL);
        if (rpg->start.is_how_to_play == true) {
            sfRenderWindow_drawSprite(rpg->window.window,
                rpg->start.sprite_menu[2].sprite, NULL);
        }
    }
}

void start_how_to_play_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->start.sprite_menu[1].sprite);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window.window,
        sfMouse_getPositionRenderWindow(rpg->window.window), NULL);
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) &&
        rpg->window.event.type == sfEvtMouseButtonPressed) {
            rpg->start.is_how_to_play = true;
    }
    if (rpg->window.event.type == sfEvtKeyPressed &&
        rpg->window.event.key.code == sfKeyEscape &&
        rpg->start.is_how_to_play == true) {
        rpg->start.is_how_to_play = false;
    }
}
