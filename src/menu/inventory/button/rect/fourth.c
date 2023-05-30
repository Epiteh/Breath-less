/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fourth_rect
*/

#include "rpg.h"
#include <stdio.h>

static void fourth_inventory_rect(rpg_t *rpg)
{
    rpg->inventory.sprite[8].texture =
        sfTexture_createFromFile("assets/menu/inventory/rect.png", NULL);
    rpg->inventory.sprite[8].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[8].sprite,
        rpg->inventory.sprite[8].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[8].sprite,
        (sfVector2f){788, 567});
}

void fourth_inventory_hover(rpg_t *rpg)
{
    rpg->inventory.is_fourth = false;
    rpg->inventory.sprite[9].texture =
        sfTexture_createFromFile("assets/menu/inventory/hover.png", NULL);
    rpg->inventory.sprite[9].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[9].sprite,
        rpg->inventory.sprite[9].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[9].sprite,
        (sfVector2f){786, 567});
}

void fourth_inventory_init(rpg_t *rpg)
{
    fourth_inventory_rect(rpg);
    fourth_inventory_hover(rpg);
}

void fourth_inventory_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[8].sprite, NULL);
    if (rpg->inventory.is_fourth)
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->inventory.sprite[9].sprite, NULL);
}

void fourth_inventory_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->inventory.sprite[8].sprite);
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
        rpg->inventory.is_fourth = true;
    } else {
        rpg->inventory.is_fourth = false;
    }
}
