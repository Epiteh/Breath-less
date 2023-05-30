/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** char_creator
*/

#include "rpg.h"

static void display_char_bg_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->creator.sprite[0].sprite, NULL);
}

static void reset_view(rpg_t *rpg)
{
    sfRenderWindow_setView(rpg->window.window,
        sfRenderWindow_getDefaultView(rpg->window.window));
}

void display_char_menu(rpg_t *rpg)
{
    reset_view(rpg);
    display_char_bg_menu(rpg);
    right_player_view(rpg);
    left_player_view(rpg);
    choice_sprite_view(rpg);
    display_speed_button(rpg);
    display_strength_button(rpg);
    display_intelligence_button(rpg);
    start_game_creator_view(rpg);
}
