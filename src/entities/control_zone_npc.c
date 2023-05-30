/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** control_zone_npc.c
*/
#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>

void valid_boss_fight(rpg_t *rpg)
{
    if (rpg->mission.do_control_fight) {
        rpg->mission_text.is_writing = true;
        rpg->mission_text.letter_counter = 0;
        sfText_setPosition(rpg->mission_text.text,
            (sfVector2f) {1555, 423});
        rpg->mission.do_control_fight = false;
        rpg->mission.do_control_fight_done = true;
        rpg->mission.go_back_safe_place = true;
    }
}

static void draw_control_zone_npc(rpg_t *rpg)
{
    bool collision = rpg->collectible.control_zone_npc.collision;
    bool is_taking = rpg->collectible.control_zone_npc.is_taking;

    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
    rpg->collectible.control_zone_npc.sprite, NULL);
    if (collision && !is_taking) {
        sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->collectible.control_zone_npc.e_interaction, NULL);
    }
    if (collision && is_taking) {
        if (draw_text_npc(rpg,
            rpg->collectible.control_zone_npc.message_content,
                rpg->collectible.control_zone_npc.message,
        &rpg->collectible.control_zone_npc.letter_counter) &&
            !rpg->mission.do_control_fight_done) {
            rpg->mission.do_control_fight = true;
            scene.scene = "boss";
        }
    }
}

void manage_control_zone_npc(rpg_t *rpg)
{
    change_e_interaction_texture(rpg,
        rpg->collectible.control_zone_npc.e_interaction, false, true);
    if (collectible_collision(rpg, rpg->collectible.control_zone_npc.rect)) {
        rpg->collectible.control_zone_npc.collision = true;
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            rpg->collectible.control_zone_npc.is_taking = true;
        }
    } else {
        rpg->collectible.control_zone_npc.collision = false;
        rpg->collectible.control_zone_npc.is_taking = false;
        rpg->collectible.control_zone_npc.letter_counter = 0;
    }
    if (rpg->collectible.control_zone_npc.collision &&
        rpg->collectible.control_zone_npc.is_taking) {
        sfRenderTexture_drawRectangleShape(rpg->background.map_render_texture,
        rpg->collectible.control_zone_npc.text_rect, NULL);
    }
    draw_control_zone_npc(rpg);
}
