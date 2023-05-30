/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** middle
*/

#include "rpg.h"

static void middle_button_txt(rpg_t *rpg)
{
    rpg->settings.txt[2].text = sfText_create();
    sfText_setString(rpg->settings.txt[2].text, "1600 x 900");
    sfText_setFont(rpg->settings.txt[2].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[2].text, 39);
    sfText_setPosition(rpg->settings.txt[2].text, (sfVector2f){1415, 366});
    sfText_setColor(rpg->settings.txt[2].text, sfBlack);
}

static void middle_button(rpg_t *rpg)
{
    rpg->settings.button[1].rect = sfRectangleShape_create();
    rpg->settings.button[1].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[1].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->settings.button[1].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->settings.button[1].rect,
        (sfVector2f){1400, 362});
    sfRectangleShape_setSize(rpg->settings.button[1].rect,
            (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[1].rect,
        rpg->settings.button[1].color.color);
    rpg->settings.button[1].is_clicked = &is_clicked;
    rpg->settings.button[1].is_hover = &is_hovered;
    rpg->settings.button[1].state = RELEASED;
}

void init_middle_button(rpg_t *rpg)
{
    middle_button_txt(rpg);
    middle_button(rpg);
}

void middle_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[1].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[2].text, NULL);
}
