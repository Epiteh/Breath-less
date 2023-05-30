/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** ceo
*/

#include "rpg.h"

void close_settings_menu(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtKeyPressed &&
        rpg->window.event.key.code == sfKeyEscape) {
            rpg->settings.is_setting = false;
            sfSound_play(rpg->settings.quitclick);
        }
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        add_fps_event(rpg);
        remove_fps_event(rpg);
    }
    choose_screen_event(rpg);
    if (rpg->settings.button[8].state == PRESSED) {
        normal_screen_event(rpg);
        middle_screen_event(rpg);
        small_screen_event(rpg);
    }
    sfx_on_button_event(rpg);
    sfx_off_button_event(rpg);
    music_off_button_event(rpg);
    music_on_button_event(rpg);
    interaction_key_button_event(rpg);
}
