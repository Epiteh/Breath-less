/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** resume
*/

#include "rpg.h"

static void start_new_button_txt(rpg_t *rpg)
{
    rpg->start.txt_menu[0].text = sfText_create();
    sfText_setString(rpg->start.txt_menu[0].text, "NEW GAME");
    sfText_setFont(rpg->start.txt_menu[0].text, rpg->font);
    sfText_setCharacterSize(rpg->start.txt_menu[0].text, 40);
    sfText_setPosition(rpg->start.txt_menu[0].text,
        (sfVector2f){170, 450});
}

static void start_new_button(rpg_t *rpg)
{
    rpg->start.button[0].rect = sfRectangleShape_create();
    rpg->start.button[0].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->start.button[0].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->start.button[0].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->start.button[0].rect,
        (sfVector2f){160, 445});
    sfRectangleShape_setSize(rpg->start.button[0].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->start.button[0].rect,
        rpg->start.button[0].color.color);
    rpg->start.button[0].is_clicked = &is_clicked;
    rpg->start.button[0].is_hover = &is_hovered;
    rpg->start.button[0].state = RELEASED;
}

void init_start_new(rpg_t *rpg)
{
    start_new_button_txt(rpg);
    start_new_button(rpg);
}

void start_new_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->start.button[0].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->start.txt_menu[0].text, NULL);
}
