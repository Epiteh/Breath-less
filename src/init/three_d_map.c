/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** three_d_map.c
*/

#include "rpg.h"

int init_three_d_map(rpg_t *rpg)
{
    rpg->background.three_sprite = sfSprite_create();
    rpg->background.three_texture =
        sfTexture_createFromFile("assets/map/main_map_3d.png", NULL);
    if (!rpg->background.three_texture)
        return (84);
    sfSprite_setTexture(rpg->background.three_sprite,
        rpg->background.three_texture, sfTrue);
    return (0);
}
