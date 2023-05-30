/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** bar_npc.c
*/

#include "rpg.h"

static int load_bar_npc(rpg_t *rpg)
{
    rpg->collectible.bar_npc.texture =
        sfTexture_createFromFile("assets/characters/npc/barman.png", NULL);
    if (!rpg->collectible.bar_npc.texture) {
        return (84);
    }
    rpg->collectible.bar_npc.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.bar_npc.sprite,
        rpg->collectible.bar_npc.texture, sfTrue);
    rpg->collectible.bar_npc.pos = (sfVector2f) {70, 850};
    sfSprite_setPosition(rpg->collectible.bar_npc.sprite,
        rpg->collectible.bar_npc.pos);
    sfSprite_setScale(rpg->collectible.bar_npc.sprite,
        (sfVector2f) {3, 3});
    return (0);
}

static void load_e_interaction(rpg_t *rpg)
{
    rpg->collectible.bar_npc.e_interaction = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.bar_npc.e_interaction,
        rpg->collectible.texture_first_e_inter, sfTrue);
    sfSprite_setPosition(rpg->collectible.bar_npc.e_interaction,
        (sfVector2f) {55 + 30, 785});
    sfSprite_setScale(rpg->collectible.bar_npc.e_interaction,
        (sfVector2f) {1.2, 1.2});
    rpg->collectible.last_second = 0;
}

static void hitbox_creation(rpg_t *rpg)
{
    rpg->collectible.bar_npc.rect = sfRectangleShape_create();
    rpg->collectible.bar_npc.rect_pos = (sfVector2f) {55, 765};
    sfRectangleShape_setPosition(rpg->collectible.bar_npc.rect,
        rpg->collectible.bar_npc.rect_pos);
    sfRectangleShape_setSize(rpg->collectible.bar_npc.rect,
        (sfVector2f){250, 250});
    sfRectangleShape_setFillColor(rpg->collectible.bar_npc.rect,
        sfTransparent);
    sfRectangleShape_setOutlineColor(
        rpg->collectible.bar_npc.rect, sfRed);
    sfRectangleShape_setOutlineThickness(
        rpg->collectible.bar_npc.rect, 2);
}

int init_bar_npc(rpg_t *rpg)
{
    if (load_bar_npc(rpg) == 84) {
        return (84);
    }
    hitbox_creation(rpg);
    load_e_interaction(rpg);
    load_bar_message(rpg);
    load_bar_npc(rpg);
    rpg->collectible.bar_npc.is_taking = false;
    return (0);
}
