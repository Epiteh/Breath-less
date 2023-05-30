/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** scene.c
*/
#include "rpg.h"

static void display_menu(rpg_t *rpg)
{
    display_hud_background_menu(rpg);
    display_draw_text_hud(rpg);
    display_escape_menu(rpg);
    if (rpg->save.is_save) {
        display_save_menu(rpg);
    }
    display_settings(rpg);
    display_inventory(rpg);
    start_how_to_play_view(rpg);
}

static void display_game(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "game") == 0) {
        display_map(rpg);
        display_game_collectibles(rpg);
        display_render_texture(rpg);
        wall_map_collision(rpg, rpg->sprite.image_bg);
        minimap(rpg);
        if (!rpg->menu.escape_menu && my_strcmp(scene.scene, "game") == 0 &&
            !rpg->save.is_save) {
            move_player(rpg);
            position(rpg);
        }
    }
}

void change_scene(rpg_t *rpg)
{
    display_game(rpg);
    if (my_strcmp(scene.scene, "bar") == 0) {
        display_bar_scene(rpg);
        manage_bar_npc(rpg);
        display_render_texture(rpg);
        wall_bar_collision(rpg, rpg->bar.image);
        if (my_strcmp(scene.scene, "bar") == 0 && !rpg->menu.escape_menu &&
            !rpg->save.is_save) {
            move_player(rpg);
            position(rpg);
        }
    }
    change_other_scene(rpg);
    display_menu(rpg);
}
