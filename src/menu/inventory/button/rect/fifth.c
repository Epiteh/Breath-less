/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fifth_rect
*/

#include "rpg.h"
#include <stdio.h>

static void fifth_inventory_rect(rpg_t *rpg)
{
    rpg->inventory.sprite[10].texture =
        sfTexture_createFromFile("assets/menu/inventory/rect.png", NULL);
    rpg->inventory.sprite[10].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[10].sprite,
        rpg->inventory.sprite[10].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[10].sprite,
        (sfVector2f){905, 567});
}

void fifth_inventory_hover(rpg_t *rpg)
{
    rpg->inventory.is_fifth = false;
    rpg->inventory.sprite[11].texture =
        sfTexture_createFromFile("assets/menu/inventory/hover.png", NULL);
    rpg->inventory.sprite[11].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[11].sprite,
        rpg->inventory.sprite[11].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[11].sprite,
        (sfVector2f){903, 567});
}

void fifth_inventory_init(rpg_t *rpg)
{
    fifth_inventory_rect(rpg);
    fifth_inventory_hover(rpg);
}

void fifth_inventory_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[10].sprite, NULL);
    if (rpg->inventory.is_fifth)
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->inventory.sprite[11].sprite, NULL);
}

void fifth_inventory_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->inventory.sprite[10].sprite);
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
        rpg->inventory.is_fifth = true;
    } else {
        rpg->inventory.is_fifth = false;
    }
}
