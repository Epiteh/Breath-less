/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** bar_npc.c
*/
#include "rpg.h"
#include <stdlib.h>

static void draw_bar_npc(rpg_t *rpg)
{
    bool collision = rpg->collectible.bar_npc.collision;
    bool is_taking = rpg->collectible.bar_npc.is_taking;

    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
    rpg->collectible.bar_npc.sprite, NULL);

    if (collision && !is_taking) {
        sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->collectible.bar_npc.e_interaction, NULL);
    }
    if (collision && is_taking) {
        draw_text_npc(rpg, rpg->collectible.bar_npc.message_content,
            rpg->collectible.bar_npc.message,
        &rpg->collectible.bar_npc.letter_counter);
    }
}

void manage_bar_npc(rpg_t *rpg)
{
    change_e_interaction_texture(rpg,
        rpg->collectible.bar_npc.e_interaction, false, true);
    if (collectible_collision(rpg, rpg->collectible.bar_npc.rect)) {
        rpg->collectible.bar_npc.collision = true;
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            rpg->collectible.bar_npc.is_taking = true;
        }
    } else {
        rpg->collectible.bar_npc.collision = false;
        rpg->collectible.bar_npc.is_taking = false;
        rpg->collectible.bar_npc.letter_counter = 0;
    }
    if (rpg->collectible.bar_npc.collision &&
        rpg->collectible.bar_npc.is_taking) {
        sfRenderTexture_drawRectangleShape(rpg->background.map_render_texture,
        rpg->collectible.bar_npc.text_rect, NULL);
    }
    draw_bar_npc(rpg);
}
