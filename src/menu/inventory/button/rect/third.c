/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** third_rect
*/

#include "rpg.h"
#include <stdio.h>

static void third_inventory_rect(rpg_t *rpg)
{
    rpg->inventory.sprite[6].texture =
        sfTexture_createFromFile("assets/menu/inventory/rect.png", NULL);
    rpg->inventory.sprite[6].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[6].sprite,
        rpg->inventory.sprite[6].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[6].sprite,
        (sfVector2f){1020, 431});
}

void third_inventory_hover(rpg_t *rpg)
{
    rpg->inventory.is_third = false;
    rpg->inventory.sprite[7].texture =
        sfTexture_createFromFile("assets/menu/inventory/hover.png", NULL);
    rpg->inventory.sprite[7].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[7].sprite,
        rpg->inventory.sprite[7].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[7].sprite,
        (sfVector2f){1018, 431});
}

void third_inventory_init(rpg_t *rpg)
{
    third_inventory_rect(rpg);
    third_inventory_hover(rpg);
}

void third_inventory_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[6].sprite, NULL);
    if (rpg->inventory.is_third)
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->inventory.sprite[7].sprite, NULL);
}

void third_inventory_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->inventory.sprite[6].sprite);
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
        rpg->inventory.is_third = true;
    } else {
        rpg->inventory.is_third = false;
    }
}
