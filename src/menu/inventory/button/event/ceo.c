/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** ceo
*/

#include "rpg.h"

static void inventory_open_close(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtKeyPressed &&
        rpg->window.event.key.code == sfKeyC &&
            rpg->inventory.inventory_open) {
            rpg->inventory.inventory_open = false;
            return;
    }
    if (rpg->window.event.type == sfEvtKeyPressed &&
        rpg->window.event.key.code == sfKeyC && !rpg->menu.escape_menu &&
            my_strcmp(scene.scene, "start") != 0 &&
                my_strcmp(scene.scene, "char_creator") != 0) {
            rpg->inventory.inventory_open = true;
    }
}

void inventory_event(rpg_t *rpg)
{
    inventory_open_close(rpg);
    first_inventory_event(rpg);
    second_inventory_event(rpg);
    third_inventory_event(rpg);
    fourth_inventory_event(rpg);
    fifth_inventory_event(rpg);
    six_inventory_event(rpg);
}
