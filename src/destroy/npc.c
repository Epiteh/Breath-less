/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** npc.c
*/

#include "rpg.h"

static void destroy_map_npc(rpg_t *rpg)
{
    sfSprite_destroy(rpg->collectible.main_place_npc.sprite);
    sfTexture_destroy(rpg->collectible.main_place_npc.texture);
    sfText_destroy(rpg->collectible.main_place_npc.message);
    sfSprite_destroy(rpg->collectible.main_place_npc.e_interaction);
    sfRectangleShape_destroy(rpg->collectible.main_place_npc.rect);
    sfRectangleShape_destroy(rpg->collectible.main_place_npc.text_rect);
    sfSprite_destroy(rpg->collectible.back_safe_place_npc.sprite);
    sfTexture_destroy(rpg->collectible.back_safe_place_npc.texture);
    sfText_destroy(rpg->collectible.back_safe_place_npc.message);
    sfSprite_destroy(rpg->collectible.back_safe_place_npc.e_interaction);
    sfRectangleShape_destroy(rpg->collectible.back_safe_place_npc.rect);
    sfRectangleShape_destroy(rpg->collectible.back_safe_place_npc.text_rect);
    sfSprite_destroy(rpg->collectible.back_safe_place_npc.first_mate_sprite);
    sfSprite_destroy(rpg->collectible.back_safe_place_npc.second_mate_sprite);
    sfTexture_destroy(rpg->collectible.back_safe_place_npc.first_mate_texture);
    sfTexture_destroy(rpg->collectible.back_safe_place_npc.second_mate_texture);
}

static void destroy_bar(rpg_t * rpg)
{
    sfSprite_destroy(rpg->collectible.bar_npc.sprite);
    sfText_destroy(rpg->collectible.bar_npc.message);
    sfTexture_destroy(rpg->collectible.bar_npc.texture);
    sfSprite_destroy(rpg->collectible.bar_npc.e_interaction);
    sfRectangleShape_destroy(rpg->collectible.bar_npc.rect);
    sfRectangleShape_destroy(rpg->collectible.bar_npc.text_rect);
}

void destroy_npc(rpg_t *rpg)
{
    destroy_map_npc(rpg);
    destroy_bar(rpg);
    sfSprite_destroy(rpg->collectible.safe_place_npc.sprite);
    sfTexture_destroy(rpg->collectible.safe_place_npc.texture);
    sfText_destroy(rpg->collectible.safe_place_npc.message);
    sfSprite_destroy(rpg->collectible.safe_place_npc.e_interaction);
    sfRectangleShape_destroy(rpg->collectible.safe_place_npc.rect);
    sfRectangleShape_destroy(rpg->collectible.safe_place_npc.text_rect);
    sfSprite_destroy(rpg->collectible.control_zone_npc.sprite);
    sfTexture_destroy(rpg->collectible.control_zone_npc.texture);
    sfText_destroy(rpg->collectible.control_zone_npc.message);
    sfSprite_destroy(rpg->collectible.control_zone_npc.e_interaction);
    sfRectangleShape_destroy(rpg->collectible.control_zone_npc.rect);
    sfRectangleShape_destroy(rpg->collectible.control_zone_npc.text_rect);
    sfClock_destroy(rpg->collectible.npc_text_clock);
}
