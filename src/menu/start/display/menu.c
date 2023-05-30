/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** menu
*/

#include "rpg.h"

static void display_start_bg_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->start.sprite_menu[0].sprite, NULL);
}

void display_start_menu(rpg_t *rpg)
{
    display_start_bg_menu(rpg);
    start_credits_view(rpg);
    start_load_view(rpg);
    start_quit_view(rpg);
    start_settings_view(rpg);
    start_new_view(rpg);
    start_how_to_play_event(rpg);
}
