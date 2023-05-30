/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings
*/

#include "rpg.h"

static void settings_button_txt(rpg_t *rpg)
{
    rpg->menu.txt_menu[2].text = sfText_create();
    sfText_setString(rpg->menu.txt_menu[2].text, "SETTINGS");
    sfText_setFont(rpg->menu.txt_menu[2].text, rpg->font);
    sfText_setCharacterSize(rpg->menu.txt_menu[2].text, 40);
    sfText_setPosition(rpg->menu.txt_menu[2].text,
        (sfVector2f){170, 600});
}

static void settings_button(rpg_t *rpg)
{
    rpg->menu.button[2].rect = sfRectangleShape_create();
    rpg->menu.button[2].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->menu.button[2].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->menu.button[2].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->menu.button[2].rect,
        (sfVector2f){160, 595});
    sfRectangleShape_setSize(rpg->menu.button[2].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->menu.button[2].rect,
        rpg->menu.button[2].color.color);
    rpg->menu.button[2].is_clicked = &is_clicked;
    rpg->menu.button[2].is_hover = &is_hovered;
    rpg->menu.button[2].state = RELEASED;
}

void init_escape_settings(rpg_t *rpg)
{
    settings_button_txt(rpg);
    settings_button(rpg);
}

void escape_settings_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->menu.button[2].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->menu.txt_menu[2].text, NULL);
}
