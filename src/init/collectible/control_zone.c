/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** control_zone_npc.c
*/

#include "rpg.h"

static int load_control_zone_npc(rpg_t *rpg)
{
    rpg->collectible.control_zone_npc.texture =
        sfTexture_createFromFile("assets/characters/npc/drone.png", NULL);
    if (!rpg->collectible.control_zone_npc.texture) {
        return (84);
    }
    rpg->collectible.control_zone_npc.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.control_zone_npc.sprite,
        rpg->collectible.control_zone_npc.texture, sfTrue);
    rpg->collectible.control_zone_npc.pos = (sfVector2f) { 1100, 500};
    sfSprite_setPosition(rpg->collectible.control_zone_npc.sprite,
        rpg->collectible.control_zone_npc.pos);
    sfSprite_setScale(rpg->collectible.control_zone_npc.sprite,
        (sfVector2f) {1.1, 1});
    return (0);
}

static void load_e_interaction(rpg_t *rpg)
{
    rpg->collectible.control_zone_npc.e_interaction = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.control_zone_npc.e_interaction,
        rpg->collectible.texture_first_e_inter, sfTrue);
    sfSprite_setPosition(rpg->collectible.control_zone_npc.e_interaction,
        (sfVector2f) {1105, 425});
    sfSprite_setScale(rpg->collectible.control_zone_npc.e_interaction,
        (sfVector2f) {1.2, 1.2});
    rpg->collectible.last_second = 0;
}

static void hitbox_creation(rpg_t *rpg)
{
    rpg->collectible.control_zone_npc.rect = sfRectangleShape_create();
    rpg->collectible.control_zone_npc.rect_pos = (sfVector2f) {1070, 485};
    sfRectangleShape_setPosition(rpg->collectible.control_zone_npc.rect,
        rpg->collectible.control_zone_npc.rect_pos);
    sfRectangleShape_setSize(rpg->collectible.control_zone_npc.rect,
        (sfVector2f){150, 150});
    sfRectangleShape_setFillColor(rpg->collectible.control_zone_npc.rect,
        sfTransparent);
    sfRectangleShape_setOutlineColor(
        rpg->collectible.control_zone_npc.rect, sfRed);
    sfRectangleShape_setOutlineThickness(
        rpg->collectible.control_zone_npc.rect, 2);
}

int init_control_zone_npc(rpg_t *rpg)
{
    if (load_control_zone_npc(rpg) == 84) {
        return (84);
    }
    hitbox_creation(rpg);
    load_e_interaction(rpg);
    load_control_zone_message(rpg);
    load_control_zone_npc(rpg);
    rpg->collectible.control_zone_npc.is_taking = false;
    return (0);
}
