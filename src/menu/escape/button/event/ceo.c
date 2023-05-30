/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** main
*/

#include "rpg.h"

static void escape_open_close(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtKeyPressed &&
        rpg->window.event.key.code == sfKeyEscape &&
            rpg->menu.escape_menu &&
                rpg->settings.is_setting == false) {
                    rpg->menu.escape_menu = false;
                    return;
                }
    if (rpg->window.event.type == sfEvtKeyPressed &&
            rpg->window.event.key.code == sfKeyEscape &&
            rpg->settings.is_setting == false &&
                my_strcmp(scene.scene, "start") != 0 &&
                    my_strcmp(scene.scene, "load") != 0 &&
                        my_strcmp(scene.scene, "char_creator") != 0 &&
                            my_strcmp(scene.scene, "loader") != 0 &&
                                my_strcmp(scene.scene, "settings") != 0 &&
                                    rpg->inventory.inventory_open == false) {
            rpg->menu.escape_menu = true;
        }
}

void escape_button_event(rpg_t *rpg)
{
    escape_open_close(rpg);
    if (rpg->menu.escape_menu) {
        escape_credits_event(rpg);
        escape_quit_event(rpg);
        escape_load_event(rpg);
        escape_resume_event(rpg);
        escape_settings_event(rpg);
        start_how_to_play_event(rpg);
    }
}
