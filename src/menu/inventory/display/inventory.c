/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** inventory
*/

#include "rpg.h"

static void reset_view_inventory(rpg_t *rpg)
{
    sfRenderWindow_setView(rpg->window.window,
        sfRenderWindow_getDefaultView(rpg->window.window));
}

void display_inventory(rpg_t *rpg)
{
    if (rpg->inventory.inventory_open) {
        reset_view_inventory(rpg);
        first_inventory_view(rpg);
        third_inventory_view(rpg);
        display_inventory_title(rpg);
        second_inventory_view(rpg);
        fourth_inventory_view(rpg);
        fifth_inventory_view(rpg);
        six_inventory_view(rpg);
        if (rpg->mission.catch_knife_done) {
            sfRenderWindow_drawSprite(rpg->window.window,
                rpg->knife_in_inventory, NULL);
        }
    }
}
