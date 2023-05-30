/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quit_game
*/

#include "rpg.h"

static void quit_game_button_txt(rpg_t *rpg)
{
    rpg->menu.txt_menu[4].text = sfText_create();
    sfText_setString(rpg->menu.txt_menu[4].text, "QUIT GAME");
    sfText_setFont(rpg->menu.txt_menu[4].text, rpg->font);
    sfText_setCharacterSize(rpg->menu.txt_menu[4].text, 40);
    sfText_setPosition(rpg->menu.txt_menu[4].text,
        (sfVector2f){170, 750});
}

static void quit_game_button(rpg_t *rpg)
{
    rpg->menu.button[4].rect = sfRectangleShape_create();
    rpg->menu.button[4].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->menu.button[4].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->menu.button[4].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->menu.button[4].rect,
        (sfVector2f){160, 745});
    sfRectangleShape_setSize(rpg->menu.button[4].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->menu.button[4].rect,
        rpg->menu.button[4].color.color);
    rpg->menu.button[4].is_clicked = &is_clicked;
    rpg->menu.button[4].is_hover = &is_hovered;
    rpg->menu.button[4].state = RELEASED;
}

void init_escape_quit(rpg_t *rpg)
{
    quit_game_button_txt(rpg);
    quit_game_button(rpg);
}

void escape_quit_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->menu.button[4].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->menu.txt_menu[4].text, NULL);
}
