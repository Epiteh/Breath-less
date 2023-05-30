/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** change_e_interaction_texture.c
*/

#include "rpg.h"

void change_e_interaction_texture(rpg_t *rpg, sfSprite *e_interaction, bool get,
    bool last)
{
    float sec;
    unsigned int actual_second;

    if (get)
        return;
    sec = sfTime_asSeconds(sfClock_getElapsedTime(
        rpg->collectible.clock));
    actual_second = (unsigned int) sec;
    if (actual_second > rpg->collectible.last_second) {
        if (last) {
            rpg->collectible.last_second = actual_second;
        }
        if (actual_second % 2 == 0) {
            sfSprite_setTexture(e_interaction,
            rpg->collectible.texture_first_e_inter, sfTrue);
        } else {
            sfSprite_setTexture(e_interaction,
            rpg->collectible.texture_second_e_inter, sfTrue);
        }
    }
}
