/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quit_game
*/

#include "rpg.h"

static void start_quit_game_button_txt(rpg_t *rpg)
{
    rpg->start.txt_menu[4].text = sfText_create();
    sfText_setString(rpg->start.txt_menu[4].text, "QUIT GAME");
    sfText_setFont(rpg->start.txt_menu[4].text, rpg->font);
    sfText_setCharacterSize(rpg->start.txt_menu[4].text, 40);
    sfText_setPosition(rpg->start.txt_menu[4].text,
        (sfVector2f){170, 750});
}

static void start_quit_game_button(rpg_t *rpg)
{
    rpg->start.button[4].rect = sfRectangleShape_create();
    rpg->start.button[4].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->start.button[4].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->start.button[4].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->start.button[4].rect,
        (sfVector2f){160, 745});
    sfRectangleShape_setSize(rpg->start.button[4].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->start.button[4].rect,
        rpg->start.button[4].color.color);
    rpg->start.button[4].is_clicked = &is_clicked;
    rpg->start.button[4].is_hover = &is_hovered;
    rpg->start.button[4].state = RELEASED;
}

void init_start_quit(rpg_t *rpg)
{
    start_quit_game_button_txt(rpg);
    start_quit_game_button(rpg);
}

void start_quit_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->start.button[4].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->start.txt_menu[4].text, NULL);
}
