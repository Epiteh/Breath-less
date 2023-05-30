/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** load_game
*/

#include "rpg.h"

static void start_load_game_button_txt(rpg_t *rpg)
{
    rpg->start.txt_menu[1].text = sfText_create();
    sfText_setString(rpg->start.txt_menu[1].text, "LOAD GAME");
    sfText_setFont(rpg->start.txt_menu[1].text, rpg->font);
    sfText_setCharacterSize(rpg->start.txt_menu[1].text, 40);
    sfText_setPosition(rpg->start.txt_menu[1].text,
        (sfVector2f){170, 525});
}

static void start_load_game_button(rpg_t *rpg)
{
    rpg->start.button[1].rect = sfRectangleShape_create();
    rpg->start.button[1].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->start.button[1].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->start.button[1].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->start.button[1].rect,
        (sfVector2f){160, 520});
    sfRectangleShape_setSize(rpg->start.button[1].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->start.button[1].rect,
        rpg->start.button[1].color.color);
    rpg->start.button[1].is_clicked = &is_clicked;
    rpg->start.button[1].is_hover = &is_hovered;
    rpg->start.button[1].state = RELEASED;
}

void init_start_load(rpg_t *rpg)
{
    start_load_game_button_txt(rpg);
    start_load_game_button(rpg);
}

void start_load_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->start.button[1].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->start.txt_menu[1].text, NULL);
}
