/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** missions.c
*/

#include "rpg.h"

void destroy_missions(rpg_t *rpg)
{
    sfText_destroy(rpg->mission_text.text);
    sfSprite_destroy(rpg->mission_text.small_sprite);
    sfSprite_destroy(rpg->mission_text.large_sprite);
    sfTexture_destroy(rpg->mission_text.small_texture);
    sfTexture_destroy(rpg->mission_text.large_texture);
    sfClock_destroy(rpg->mission_text.clock);
}
