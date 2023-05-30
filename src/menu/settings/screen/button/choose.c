/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** choose
*/

#include "rpg.h"

static void choose_button_txt(rpg_t *rpg)
{
    rpg->settings.screen.str = my_calloc(10, sizeof(char));
    rpg->settings.screen.str = "1920 x 1080";
    rpg->settings.txt[10].text = sfText_create();
    sfText_setString(rpg->settings.txt[10].text,
        rpg->settings.screen.str);
    sfText_setFont(rpg->settings.txt[10].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[10].text, 39);
    sfText_setPosition(rpg->settings.txt[10].text,
        (sfVector2f){1125, 304});
    sfText_setColor(rpg->settings.txt[10].text, sfBlack);
}

static void choose_button(rpg_t *rpg)
{
    rpg->settings.button[8].rect = sfRectangleShape_create();
    rpg->settings.button[8].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[8].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->settings.button[8].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->settings.button[8].rect,
        (sfVector2f){1110, 300});
    sfRectangleShape_setSize(rpg->settings.button[8].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[8].rect,
        rpg->settings.button[8].color.color);
    rpg->settings.button[8].is_clicked = &is_clicked;
    rpg->settings.button[8].is_hover = &is_hovered;
    rpg->settings.button[8].state = RELEASED;
}

void init_choose_button(rpg_t *rpg)
{
    choose_button_txt(rpg);
    choose_button(rpg);
}

void choose_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[8].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[10].text, NULL);
}
