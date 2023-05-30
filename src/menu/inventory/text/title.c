/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** title
*/

#include "rpg.h"

void init_inventory_title(rpg_t *rpg)
{
    rpg->inventory.sprite[0].sprite = sfSprite_create();
    rpg->inventory.sprite[0].texture =
        sfTexture_createFromFile("assets/menu/inventory/txt.png", NULL);
    sfSprite_setTexture(rpg->inventory.sprite[0].sprite,
        rpg->inventory.sprite[0].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[0].sprite,
        (sfVector2f){0, 0});
}

void init_inventory_background(rpg_t *rpg)
{
    rpg->inventory.sprite[1].sprite = sfSprite_create();
    rpg->inventory.sprite[1].texture =
        sfTexture_createFromFile("assets/menu/inventory/background.png", NULL);
    sfSprite_setTexture(rpg->inventory.sprite[1].sprite,
        rpg->inventory.sprite[1].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[1].sprite,
        (sfVector2f){0, 0});
}

void display_inventory_title(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[1].sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[0].sprite, NULL);
}
