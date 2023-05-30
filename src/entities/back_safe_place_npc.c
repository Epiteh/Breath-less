/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** back_safe_place.c
*/
#include "rpg.h"
#include <stdio.h>

static void draw_back_safe_place_npc(rpg_t *rpg)
{
    bool collision = rpg->collectible.back_safe_place_npc.collision;
    bool is_taking = rpg->collectible.back_safe_place_npc.is_taking;

    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
    rpg->collectible.back_safe_place_npc.sprite, NULL);

    if (collision && !is_taking) {
        sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->collectible.back_safe_place_npc.e_interaction, NULL);
    }
    if (collision && is_taking) {
        draw_text_npc(rpg,
            rpg->collectible.back_safe_place_npc.message_content,
                rpg->collectible.back_safe_place_npc.message,
        &rpg->collectible.back_safe_place_npc.letter_counter);
    }
}

static void sub_manage_back_safe_place_npc(rpg_t *rpg)
{
    sfRenderTexture_drawRectangleShape(rpg->background.map_render_texture,
        rpg->collectible.back_safe_place_npc.rect, NULL);
    draw_back_safe_place_npc(rpg);
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->collectible.back_safe_place_npc.first_mate_sprite, NULL);
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->collectible.back_safe_place_npc.second_mate_sprite, NULL);
}

void manage_back_safe_place_npc(rpg_t *rpg)
{
    change_e_interaction_texture(rpg,
        rpg->collectible.back_safe_place_npc.e_interaction, false, true);
    if (collectible_collision(rpg,
        rpg->collectible.back_safe_place_npc.rect)) {
        rpg->collectible.back_safe_place_npc.collision = true;
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            rpg->collectible.back_safe_place_npc.is_taking = true;
        }
    } else {
        rpg->collectible.back_safe_place_npc.collision = false;
        rpg->collectible.back_safe_place_npc.is_taking = false;
        rpg->collectible.back_safe_place_npc.letter_counter = 0;
    }
    if (rpg->collectible.back_safe_place_npc.collision &&
        rpg->collectible.back_safe_place_npc.is_taking) {
        sfRenderTexture_drawRectangleShape(rpg->background.map_render_texture,
        rpg->collectible.back_safe_place_npc.text_rect, NULL);
    }
    sub_manage_back_safe_place_npc(rpg);
}
