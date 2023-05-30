/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** knife.c
*/

#include "rpg.h"

static int load_main_place_npc(rpg_t *rpg)
{
    rpg->collectible.main_place_npc.texture =
        sfTexture_createFromFile("assets/characters/npc/drone.png", NULL);
    if (!rpg->collectible.main_place_npc.texture) {
        return (84);
    }
    rpg->collectible.main_place_npc.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.main_place_npc.sprite,
        rpg->collectible.main_place_npc.texture, sfTrue);
    rpg->collectible.main_place_npc.pos = (sfVector2f) {660, 1460};
    sfSprite_setPosition(rpg->collectible.main_place_npc.sprite,
        rpg->collectible.main_place_npc.pos);
    sfSprite_setScale(rpg->collectible.main_place_npc.sprite,
        (sfVector2f) {0.8, 0.7});
    return (0);
}

static void load_e_interaction(rpg_t *rpg)
{
    rpg->collectible.main_place_npc.e_interaction = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.main_place_npc.e_interaction,
        rpg->collectible.texture_first_e_inter, sfTrue);
    sfSprite_setPosition(rpg->collectible.main_place_npc.e_interaction,
        (sfVector2f) {635 + 25, 1460 - 50});
    sfSprite_setScale(rpg->collectible.main_place_npc.e_interaction,
        (sfVector2f) {0.9, 0.9});
    rpg->collectible.last_second = 0;
}

static void hitbox_creation(rpg_t *rpg)
{
    rpg->collectible.main_place_npc.rect = sfRectangleShape_create();
    rpg->collectible.main_place_npc.rect_pos = (sfVector2f) {605, 1430};
    sfRectangleShape_setPosition(rpg->collectible.main_place_npc.rect,
        rpg->collectible.main_place_npc.rect_pos);
    sfRectangleShape_setSize(rpg->collectible.main_place_npc.rect,
        (sfVector2f){150, 150});
    sfRectangleShape_setFillColor(rpg->collectible.main_place_npc.rect,
        sfTransparent);
    sfRectangleShape_setOutlineColor(
        rpg->collectible.main_place_npc.rect, sfRed);
    sfRectangleShape_setOutlineThickness(
        rpg->collectible.main_place_npc.rect, 2);
}

int init_main_place_npc(rpg_t *rpg)
{
    if (load_main_place_npc(rpg) == 84) {
        return (84);
    }
    hitbox_creation(rpg);
    load_e_interaction(rpg);
    load_map_place_message(rpg);
    load_main_place_npc(rpg);
    rpg->collectible.main_place_npc.is_taking = false;
    return (0);
}
