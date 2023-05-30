/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** display
*/

#include "rpg.h"

void display_sound_settings(rpg_t *rpg)
{
    sfx_on_button_view(rpg);
    sfx_off_button_view(rpg);
    music_on_button_view(rpg);
    music_off_button_view(rpg);
}
