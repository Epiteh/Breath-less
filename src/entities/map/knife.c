/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** knife.c
*/

#include "rpg.h"

static void draw_collectible(rpg_t *rpg, sfSprite *sprite,
    sfSprite *e_interaction, bool get)
{
    if (!get) {
        sfRenderTexture_drawSprite(rpg->background.map_render_texture,
            sprite, NULL);
        if (rpg->collectible.knife.collision) {
            sfRenderTexture_drawSprite(rpg->background.map_render_texture,
                e_interaction, NULL);
        }
    }
}

static void sub_manage_map_collectibles(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (!rpg->mission.catch_knife_done) {
            rpg->mission.catch_knife = false;
            rpg->mission.go_place = true;
            rpg->mission_text.is_writing = true;
            rpg->mission_text.letter_counter = 0;
            sfText_setPosition(rpg->mission_text.text,
                (sfVector2f) {1525 + 90, 410 + 13});
        }
        rpg->mission.catch_knife_done = true;
        rpg->collectible.knife.get = true;
    }
}

void manage_map_collectibles(rpg_t *rpg)
{
    change_e_interaction_texture(rpg, rpg->collectible.knife.e_interaction,
        rpg->collectible.knife.get, false);

    if (map_collectible_collision(rpg, rpg->collectible.knife.rect)) {
        rpg->collectible.knife.collision = true;
        sub_manage_map_collectibles(rpg);
    } else {
        rpg->collectible.knife.collision = false;
    }
    draw_collectible(rpg, rpg->collectible.knife.sprite,
        rpg->collectible.knife.e_interaction, rpg->collectible.knife.get);
}
