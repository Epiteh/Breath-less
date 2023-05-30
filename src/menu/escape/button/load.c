/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** load_game
*/

#include "rpg.h"

static void load_game_button_txt(rpg_t *rpg)
{
    rpg->menu.txt_menu[1].text = sfText_create();
    sfText_setString(rpg->menu.txt_menu[1].text, "SAVE GAME");
    sfText_setFont(rpg->menu.txt_menu[1].text, rpg->font);
    sfText_setCharacterSize(rpg->menu.txt_menu[1].text, 40);
    sfText_setPosition(rpg->menu.txt_menu[1].text,
        (sfVector2f){170, 525});
}

static void load_game_button(rpg_t *rpg)
{
    rpg->menu.button[1].rect = sfRectangleShape_create();
    rpg->menu.button[1].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->menu.button[1].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->menu.button[1].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->menu.button[1].rect,
        (sfVector2f){160, 520});
    sfRectangleShape_setSize(rpg->menu.button[1].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->menu.button[1].rect,
        rpg->menu.button[1].color.color);
    rpg->menu.button[1].is_clicked = &is_clicked;
    rpg->menu.button[1].is_hover = &is_hovered;
    rpg->menu.button[1].state = RELEASED;
}

void init_escape_load(rpg_t *rpg)
{
    load_game_button_txt(rpg);
    load_game_button(rpg);
}

void escape_load_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->menu.button[1].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->menu.txt_menu[1].text, NULL);
}
