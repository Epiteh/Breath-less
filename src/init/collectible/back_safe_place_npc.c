/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** back_safe_place_npc.c
*/

#include "rpg.h"

static int load_back_safe_place_npc(rpg_t *rpg)
{
    rpg->collectible.back_safe_place_npc.texture =
        sfTexture_createFromFile("assets/characters/npc/speaker.png", NULL);
    if (!rpg->collectible.back_safe_place_npc.texture) {
        return (84);
    }
    rpg->collectible.back_safe_place_npc.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.back_safe_place_npc.sprite,
        rpg->collectible.back_safe_place_npc.texture, sfTrue);
    rpg->collectible.back_safe_place_npc.pos = (sfVector2f) {232 + 20, 2100};
    sfSprite_setPosition(rpg->collectible.back_safe_place_npc.sprite,
        rpg->collectible.back_safe_place_npc.pos);
    sfSprite_setScale(rpg->collectible.back_safe_place_npc.sprite,
        (sfVector2f) {1.7, 1.7});
    return (0);
}

static void load_e_interaction(rpg_t *rpg)
{
    rpg->collectible.back_safe_place_npc.e_interaction = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.back_safe_place_npc.e_interaction,
        rpg->collectible.texture_first_e_inter, sfTrue);
    sfSprite_setPosition(rpg->collectible.back_safe_place_npc.e_interaction,
        (sfVector2f) {254, 2050});
    sfSprite_setScale(rpg->collectible.back_safe_place_npc.e_interaction,
        (sfVector2f) {0.9, 0.9});
    rpg->collectible.last_second = 0;
}

static void hitbox_creation(rpg_t *rpg)
{
    rpg->collectible.back_safe_place_npc.rect = sfRectangleShape_create();
    rpg->collectible.back_safe_place_npc.rect_pos = (sfVector2f) {182, 2060};
    sfRectangleShape_setPosition(rpg->collectible.back_safe_place_npc.rect,
        rpg->collectible.back_safe_place_npc.rect_pos);
    sfRectangleShape_setSize(rpg->collectible.back_safe_place_npc.rect,
        (sfVector2f){200, 200});
    sfRectangleShape_setFillColor(rpg->collectible.back_safe_place_npc.rect,
        sfTransparent);
    sfRectangleShape_setOutlineColor(
        rpg->collectible.back_safe_place_npc.rect, sfRed);
}

int init_back_safe_place_npc(rpg_t *rpg)
{
    if (load_back_safe_place_npc(rpg) == 84) {
        return (84);
    }
    hitbox_creation(rpg);
    load_e_interaction(rpg);
    load_back_safe_place_message(rpg);
    load_back_safe_place_npc(rpg);
    init_back_safe_place_mate_npc(rpg);
    rpg->collectible.back_safe_place_npc.is_taking = false;
    return (0);
}
