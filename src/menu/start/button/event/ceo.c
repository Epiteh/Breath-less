/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** main
*/

#include "rpg.h"

void start_button_event(rpg_t *rpg)
{
    if (!rpg->save.is_load) {
        start_credits_event(rpg);
        start_load_event(rpg);
        start_quit_event(rpg);
        start_settings_event(rpg);
        start_new_event(rpg);
        start_how_to_play_event(rpg);
    }
}
