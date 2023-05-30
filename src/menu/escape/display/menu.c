/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** menu
*/

#include "rpg.h"

static void display_escape_bg_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->menu.sprite_menu[0].sprite, NULL);
}

static void reset_view(rpg_t *rpg)
{
    sfRenderWindow_setView(rpg->window.window,
        sfRenderWindow_getDefaultView(rpg->window.window));
}

void display_escape_menu(rpg_t *rpg)
{
    if (rpg->menu.escape_menu) {
        reset_view(rpg);
        display_escape_bg_menu(rpg);
        escape_credits_view(rpg);
        escape_load_view(rpg);
        escape_quit_view(rpg);
        escape_settings_view(rpg);
        escape_resume_view(rpg);
    }
}
