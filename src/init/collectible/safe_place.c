/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** safe_place_npc.c
*/

#include "rpg.h"

static int load_safe_place_npc(rpg_t *rpg)
{
    rpg->collectible.safe_place_npc.texture =
        sfTexture_createFromFile("assets/characters/npc/planque.png", NULL);
    if (!rpg->collectible.safe_place_npc.texture) {
        return (84);
    }
    rpg->collectible.safe_place_npc.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.safe_place_npc.sprite,
        rpg->collectible.safe_place_npc.texture, sfTrue);
    rpg->collectible.safe_place_npc.pos = (sfVector2f) {- 10, 375};
    sfSprite_setPosition(rpg->collectible.safe_place_npc.sprite,
        rpg->collectible.safe_place_npc.pos);
    sfSprite_setScale(rpg->collectible.safe_place_npc.sprite,
        (sfVector2f) {3, 3});
    return (0);
}

static void load_e_interaction(rpg_t *rpg)
{
    rpg->collectible.safe_place_npc.e_interaction = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.safe_place_npc.e_interaction,
        rpg->collectible.texture_first_e_inter, sfTrue);
    sfSprite_setPosition(rpg->collectible.safe_place_npc.e_interaction,
        (sfVector2f) {10, 300});
    sfSprite_setScale(rpg->collectible.safe_place_npc.e_interaction,
        (sfVector2f) {1.2, 1.2});
    rpg->collectible.last_second = 0;
}

static void hitbox_creation(rpg_t *rpg)
{
    rpg->collectible.safe_place_npc.rect = sfRectangleShape_create();
    rpg->collectible.safe_place_npc.rect_pos = (sfVector2f) {8 - 50, 400 -40};
    sfRectangleShape_setPosition(rpg->collectible.safe_place_npc.rect,
        rpg->collectible.safe_place_npc.rect_pos);
    sfRectangleShape_setSize(rpg->collectible.safe_place_npc.rect,
        (sfVector2f){150, 150});
    sfRectangleShape_setFillColor(rpg->collectible.safe_place_npc.rect,
        sfTransparent);
    sfRectangleShape_setOutlineColor(
        rpg->collectible.safe_place_npc.rect, sfRed);
    sfRectangleShape_setOutlineThickness(
        rpg->collectible.safe_place_npc.rect, 2);
}

int init_safe_place_npc(rpg_t *rpg)
{
    if (load_safe_place_npc(rpg) == 84) {
        return (84);
    }
    hitbox_creation(rpg);
    load_e_interaction(rpg);
    load_safe_place_message(rpg);
    load_safe_place_npc(rpg);
    rpg->collectible.safe_place_npc.is_taking = false;
    return (0);
}
