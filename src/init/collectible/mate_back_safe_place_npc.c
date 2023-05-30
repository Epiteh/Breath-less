/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** mate_back_safe_place_npc.c
*/

#include "rpg.h"

static void cond_back_safe_npc(rpg_t *rpg)
{
    rpg->collectible.back_safe_place_npc.second_mate_sprite =
        sfSprite_create();
    rpg->collectible.back_safe_place_npc.second_mate_texture =
        sfTexture_createFromFile("assets/characters/npc/chet.png", NULL);
    sfSprite_setTexture(rpg->collectible.
    back_safe_place_npc.second_mate_sprite,
        rpg->collectible.
        back_safe_place_npc.second_mate_texture, sfTrue);
    sfSprite_setPosition(rpg->collectible.
    back_safe_place_npc.second_mate_sprite,
        (sfVector2f) {232 + 50, 2100});
    sfSprite_setScale(rpg->collectible.
    back_safe_place_npc.second_mate_sprite,
        (sfVector2f) {1.7, 1.7});
}

void init_back_safe_place_mate_npc(rpg_t *rpg)
{
    rpg->collectible.back_safe_place_npc.first_mate_sprite =
        sfSprite_create();
    rpg->collectible.
    back_safe_place_npc.first_mate_texture =
    sfTexture_createFromFile("assets/characters/npc/erik_jay.png", NULL);
    sfSprite_setTexture(rpg->collectible.
        back_safe_place_npc.first_mate_sprite,
        rpg->collectible.
        back_safe_place_npc.first_mate_texture, sfTrue);
    sfSprite_setPosition(rpg->collectible.back_safe_place_npc.first_mate_sprite,
        (sfVector2f) {232 - 10, 2100});
    sfSprite_setScale(rpg->collectible.back_safe_place_npc.first_mate_sprite,
        (sfVector2f) {1.7, 1.7});
    cond_back_safe_npc(rpg);
}
