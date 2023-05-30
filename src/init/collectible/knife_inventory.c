/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** knife_inventory.c
*/

#include "rpg.h"

void init_knife_inventory(rpg_t *rpg)
{
    rpg->knife_in_inventory = sfSprite_create();
    sfSprite_setTexture(rpg->knife_in_inventory,
        rpg->collectible.knife.texture, sfTrue);
    sfSprite_setPosition(rpg->knife_in_inventory, (sfVector2f){765, 415});
    sfSprite_setScale(rpg->knife_in_inventory, (sfVector2f){5, 5});
}
