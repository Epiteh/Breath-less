/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** second_rect
*/

#include "rpg.h"
#include <stdio.h>

static void second_inventory_rect(rpg_t *rpg)
{
    rpg->inventory.sprite[4].texture =
        sfTexture_createFromFile("assets/menu/inventory/rect.png", NULL);
    rpg->inventory.sprite[4].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[4].sprite,
        rpg->inventory.sprite[4].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[4].sprite,
        (sfVector2f){905, 431});
}

void second_inventory_hover(rpg_t *rpg)
{
    rpg->inventory.is_second = false;
    rpg->inventory.sprite[5].texture =
        sfTexture_createFromFile("assets/menu/inventory/hover.png", NULL);
    rpg->inventory.sprite[5].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->inventory.sprite[5].sprite,
        rpg->inventory.sprite[5].texture, sfTrue);
    sfSprite_setPosition(rpg->inventory.sprite[5].sprite,
        (sfVector2f){903, 431});
}

void second_inventory_init(rpg_t *rpg)
{
    second_inventory_rect(rpg);
    second_inventory_hover(rpg);
}

void second_inventory_view(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->inventory.sprite[4].sprite, NULL);
    if (rpg->inventory.is_second)
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->inventory.sprite[5].sprite, NULL);
}

void second_inventory_event(rpg_t *rpg)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(
        rpg->inventory.sprite[4].sprite);
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
        rpg->inventory.is_second = true;
    } else {
        rpg->inventory.is_second = false;
    }
}
