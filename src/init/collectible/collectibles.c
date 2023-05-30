/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** collectibles.c
*/

#include "rpg.h"

static int init_e_interact(rpg_t *rpg)
{
    rpg->collectible.texture_first_e_inter = sfTexture_createFromFile(
        "assets/collectibles/interact_frame_1.png", NULL);
    if (!rpg->collectible.texture_first_e_inter) {
        return (84);
    }
    rpg->collectible.texture_second_e_inter = sfTexture_createFromFile(
        "assets/collectibles/interact_frame_2.png", NULL);
    if (!rpg->collectible.texture_second_e_inter) {
        return (84);
    }
    rpg->collectible.clock = sfClock_create();
    if (!rpg->collectible.clock) {
        return (84);
    }
    return (0);
}

static int do_cond_collectibles(rpg_t *rpg)
{
    if (init_bar_npc(rpg) == 84) {
        return (84);
    }
    if (init_safe_place_npc(rpg) == 84) {
        return (84);
    }
    if (init_control_zone_npc(rpg) == 84) {
        return (84);
    }
    if (init_back_safe_place_npc(rpg) == 84) {
        return (84);
    }
    return (0);
}

int init_collectibles(rpg_t *rpg)
{
    rpg->collectible.npc_text_clock = sfClock_create();
    if (!rpg->collectible.npc_text_clock) {
        return (84);
    }
    if (init_e_interact(rpg) == 84) {
        return (84);
    }
    if (init_knife(rpg) == 84) {
        return (84);
    }
    if (init_main_place_npc(rpg) == 84) {
        return (84);
    }
    do_cond_collectibles(rpg);
    init_knife_inventory(rpg);
    return (0);
}
