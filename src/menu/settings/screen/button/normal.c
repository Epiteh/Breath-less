/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** normal
*/

#include "rpg.h"

static void normal_button_txt(rpg_t *rpg)
{
    rpg->settings.txt[1].text = sfText_create();
    sfText_setString(rpg->settings.txt[1].text, "1920 x 1080");
    sfText_setFont(rpg->settings.txt[1].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[1].text, 39);
    sfText_setPosition(rpg->settings.txt[1].text, (sfVector2f){1415, 304});
    sfText_setColor(rpg->settings.txt[1].text, sfBlack);
}

static void normal_button(rpg_t *rpg)
{
    rpg->settings.button[0].rect = sfRectangleShape_create();
    rpg->settings.button[0].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[0].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->settings.button[0].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->settings.button[0].rect,
        (sfVector2f){1400, 300});
    sfRectangleShape_setSize(rpg->settings.button[0].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[0].rect,
        rpg->settings.button[0].color.color);
    rpg->settings.button[0].is_clicked = &is_clicked;
    rpg->settings.button[0].is_hover = &is_hovered;
    rpg->settings.button[0].state = RELEASED;
}

void init_normal_button(rpg_t *rpg)
{
    normal_button_txt(rpg);
    normal_button(rpg);
}

void normal_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[0].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[1].text, NULL);
}
