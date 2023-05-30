/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** collectibles.c
*/

#include "rpg.h"

void destroy_collectibles(rpg_t *rpg)
{
    sfSprite_destroy(rpg->collectible.knife.sprite);
    sfSprite_destroy(rpg->collectible.knife.e_interaction);
    sfTexture_destroy(rpg->collectible.knife.texture);
    sfRectangleShape_destroy(rpg->collectible.knife.rect);
    sfTexture_destroy(rpg->collectible.texture_first_e_inter);
    sfTexture_destroy(rpg->collectible.texture_second_e_inter);
    sfClock_destroy(rpg->collectible.clock);
}
