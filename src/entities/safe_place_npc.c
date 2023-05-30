/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** safe_place_npc.c
*/
#include "rpg.h"

static void draw_safe_place_npc(rpg_t *rpg)
{
    bool collision = rpg->collectible.safe_place_npc.collision;
    bool is_taking = rpg->collectible.safe_place_npc.is_taking;

    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
    rpg->collectible.safe_place_npc.sprite, NULL);
    if (collision && !is_taking) {
        sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->collectible.safe_place_npc.e_interaction, NULL);
    }
    if (collision && is_taking) {
        draw_text_npc(rpg, rpg->collectible.safe_place_npc.message_content,
            rpg->collectible.safe_place_npc.message,
        &rpg->collectible.safe_place_npc.letter_counter);
    }
}

static void do_cond_manage_safe_place_npc(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        rpg->collectible.safe_place_npc.is_taking = true;
    }
}

void manage_safe_place_npc(rpg_t *rpg)
{
    change_e_interaction_texture(rpg,
        rpg->collectible.safe_place_npc.e_interaction, false, true);
    if (collectible_collision(rpg, rpg->collectible.safe_place_npc.rect)) {
        rpg->collectible.safe_place_npc.collision = true;
        do_cond_manage_safe_place_npc(rpg);
    } else {
        rpg->collectible.safe_place_npc.collision = false;
        rpg->collectible.safe_place_npc.is_taking = false;
        rpg->collectible.safe_place_npc.letter_counter = 0;
    }
    if (rpg->collectible.safe_place_npc.collision &&
        rpg->collectible.safe_place_npc.is_taking) {
        sfRenderTexture_drawRectangleShape(rpg->background.map_render_texture,
        rpg->collectible.safe_place_npc.text_rect, NULL);
    }
    draw_safe_place_npc(rpg);
}
