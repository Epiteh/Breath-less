/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** init
*/

#include "rpg.h"

void init_sound_settings(rpg_t *rpg)
{
    init_sfx_on_button(rpg);
    init_sfx_off_button(rpg);
    init_music_on_button(rpg);
    init_music_off_button(rpg);
}
