/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** first_rect
*/

#include "rpg.h"
#include <stdio.h>
#include <stdbool.h>

static void first_inventory_rect(rpg_t *rpg)
{
    rpg->inventory.sprite[2].texture =
        sfTexture_createFromFile("assets/menu/inventory/rect.png", NULL);
    rpg->inventory.sprite[2].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[2].sprite,
        rpg->inventory.sprite[2].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[2].sprite,
        (sfVector2f){788, 431});
}

void first_inventory_hover(rpg_t *rpg)
{
    rpg->inventory.is_first = false;
    rpg->inventory.sprite[3].texture =
        sfTexture_createFromFile("assets/menu/inventory/hover.png", NULL);
    rpg->inventory.sprite[3].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[3].sprite,
        rpg->inventory.sprite[3].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[3].sprite,
        (sfVector2f){786, 431});
}

void first_inventory_init(rpg_t *rpg)
{
    first_inventory_rect(rpg);
    first_inventory_hover(rpg);
}

void first_inventory_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[2].sprite, NULL);
    if (rpg->inventory.is_first)
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->inventory.sprite[3].sprite, NULL);
}

void first_inventory_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->inventory.sprite[2].sprite);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(rpg->window.window,
        sfMouse_getPositionRenderWindow(rpg->window.window), NULL);

    if (rpg->window.event.type == sfEvtMouseButtonPressed &&
        rpg->window.event.mouseButton.button == sfMouseLeft &&
            rpg->inventory.inventory_open &&
                sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        printf("Tu as réussi mon chef\n");
    }
    if (rpg->window.event.type == sfEvtMouseMoved &&
        rpg->inventory.inventory_open &&
            sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        rpg->inventory.is_first = true;
    } else {
        rpg->inventory.is_first = false;
    }
}
