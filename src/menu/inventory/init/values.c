/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** values
*/

#include "rpg.h"

static void init_inventory_buttons(rpg_t *rpg)
{
    init_inventory_background(rpg);
    init_inventory_title(rpg);
    first_inventory_init(rpg);
    second_inventory_init(rpg);
    third_inventory_init(rpg);
    fourth_inventory_init(rpg);
    fifth_inventory_init(rpg);
    six_inventory_init(rpg);
}

static void init_inventory_struct(rpg_t *rpg)
{
    rpg->inventory.inventory_open = false;
    rpg->inventory.sprite = my_calloc(14,
        sizeof(struct sprite_inventory));
}

void init_inventory_values(rpg_t *rpg)
{
    init_inventory_struct(rpg);
    init_inventory_buttons(rpg);
}
