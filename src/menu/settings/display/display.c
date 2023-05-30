/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** display
*/

#include "rpg.h"

static void display_screen_size(rpg_t *rpg)
{
    choose_button_view(rpg);
    if (rpg->settings.button[8].state == PRESSED) {
        middle_button_view(rpg);
        normal_button_view(rpg);
        small_button_view(rpg);
    }
}

static void display_settings_background(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->settings.sprite[0].sprite, NULL);
}

void display_settings(rpg_t *rpg)
{
    if (rpg->settings.is_setting == true) {
        display_settings_background(rpg);
        display_screen_size(rpg);

        fps_number_view(rpg);
        add_fps_view(rpg);
        remove_fps_view(rpg);
        hdr_number_view(rpg);
        display_sound_settings(rpg);
        interaction_key_button_view(rpg);
    }
}
