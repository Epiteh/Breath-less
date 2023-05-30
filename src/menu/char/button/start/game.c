/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** start_game
*/

#include "rpg.h"
#include <stdbool.h>

void start_game_creator_view(rpg_t *rpg)
{
    if (rpg->creator.is_hover) {
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->creator.sprite[6].sprite, NULL);
    }
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->creator.sprite[5].sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->creator.sprite[7].sprite, NULL);
}

static void choose_player_sprite(rpg_t *rpg)
{
    if (rpg->creator.index == 3) {
        rpg->sprite.down = "./assets/characters/mc/river_down.png";
        rpg->sprite.up = "./assets/characters/mc/river_up.png";
        rpg->sprite.left = "./assets/characters/mc/river_left.png";
        rpg->sprite.right = "./assets/characters/mc/river_right.png";
        rpg->sprite.sprite_path = "./assets/characters/mc/river_down.png";
    } else {
        rpg->sprite.down = "./assets/characters/mc/lucy_down.png";
        rpg->sprite.up = "./assets/characters/mc/lucy_up.png";
        rpg->sprite.left = "./assets/characters/mc/lucy_left.png";
        rpg->sprite.right = "./assets/characters/mc/lucy_right.png";
        rpg->sprite.sprite_path = "./assets/characters/mc/lucy_down.png";
    }
    sfSprite_setTexture(rpg->sprite.sprite,
        sfTexture_createFromFile(rpg->sprite.sprite_path, NULL), sfTrue);
}

void start_game_creator_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->creator.sprite[5].sprite);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window.window,
        sfMouse_getPositionRenderWindow(rpg->window.window), NULL);
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) &&
        rpg->window.event.type == sfEvtMouseButtonPressed) {
            choose_player_sprite(rpg);
            scene.scene = "bar";
    }
    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) &&
        rpg->window.event.type == sfEvtMouseMoved) {
            rpg->creator.is_hover = true;
    } else {
        rpg->creator.is_hover = false;
    }
}
