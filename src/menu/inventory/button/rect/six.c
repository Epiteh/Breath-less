/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** six_rect
*/

#include "rpg.h"
#include <stdio.h>

static void six_inventory_rect(rpg_t *rpg)
{
    rpg->inventory.sprite[12].texture =
        sfTexture_createFromFile("assets/menu/inventory/rect.png", NULL);
    rpg->inventory.sprite[12].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[12].sprite,
        rpg->inventory.sprite[12].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[12].sprite,
        (sfVector2f){1020, 567});
}

void six_inventory_hover(rpg_t *rpg)
{
    rpg->inventory.is_sixth = false;
    rpg->inventory.sprite[13].texture =
        sfTexture_createFromFile("assets/menu/inventory/hover.png", NULL);
    rpg->inventory.sprite[13].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[13].sprite,
        rpg->inventory.sprite[13].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[13].sprite,
        (sfVector2f){1018, 567});
}

void six_inventory_init(rpg_t *rpg)
{
    six_inventory_rect(rpg);
    six_inventory_hover(rpg);
}

void six_inventory_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[12].sprite, NULL);
    if (rpg->inventory.is_sixth)
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->inventory.sprite[13].sprite, NULL);
}

void six_inventory_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->inventory.sprite[12].sprite);
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
        rpg->inventory.is_sixth = true;
    } else {
        rpg->inventory.is_sixth = false;
    }
}
