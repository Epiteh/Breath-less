/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** main_place_npc.c
*/
#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>

void do_main_place_fight(rpg_t *rpg)
{
    if (rpg->mission.do_place_fight) {
        rpg->mission.go_place = false;
        rpg->mission.go_safe_place = true;
        rpg->mission_text.is_writing = true;
        rpg->mission_text.letter_counter = 10;
        rpg->mission.do_place_fight = false;
        sfText_setPosition(rpg->mission_text.text,
            (sfVector2f) {1525 + 60, 410 + 8});
        rpg->mission.do_place_fight_done = true;
    }
}

void draw_main_place_npc(rpg_t *rpg)
{
    bool collision = rpg->collectible.main_place_npc.collision;
    bool is_taking = rpg->collectible.main_place_npc.is_taking;

    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
    rpg->collectible.main_place_npc.sprite, NULL);

    if (collision && !is_taking) {
        sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->collectible.main_place_npc.e_interaction, NULL);
    }
    if (collision && is_taking) {
        if (draw_text_npc(rpg, rpg->collectible.main_place_npc.message_content,
            rpg->collectible.main_place_npc.message,
            &rpg->collectible.main_place_npc.letter_counter) &&
            !rpg->mission.do_place_fight_done) {
            rpg->mission.do_place_fight = true;
            rpg->mission.go_place_done = true;
            scene.scene = "fight";
        }
    }
}

void manage_main_place_npc(rpg_t *rpg)
{
    change_e_interaction_texture(rpg,
        rpg->collectible.main_place_npc.e_interaction, false, false);
    if (map_collectible_collision(rpg, rpg->collectible.main_place_npc.rect)) {
        rpg->collectible.main_place_npc.collision = true;
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            rpg->collectible.main_place_npc.is_taking = true;
                rpg->mission.go_place = false;
        }
    } else {
        rpg->collectible.main_place_npc.collision = false;
        rpg->collectible.main_place_npc.is_taking = false;
        rpg->collectible.main_place_npc.letter_counter = 0;
    }
    if (rpg->collectible.main_place_npc.collision &&
        rpg->collectible.main_place_npc.is_taking) {
        sfRenderTexture_drawRectangleShape(rpg->background.map_render_texture,
        rpg->collectible.main_place_npc.text_rect, NULL);
    }
    draw_main_place_npc(rpg);
}
