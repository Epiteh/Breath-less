/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** off
*/

#include "rpg.h"

static void sfx_off_button_txt(rpg_t *rpg)
{
    rpg->settings.txt[6].text = sfText_create();
    sfText_setString(rpg->settings.txt[6].text, "Off");
    sfText_setFont(rpg->settings.txt[6].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[6].text, 39);
    sfText_setPosition(rpg->settings.txt[6].text, (sfVector2f){1275, 533});
    sfText_setColor(rpg->settings.txt[6].text, sfBlack);
}

static void sfx_off_button(rpg_t *rpg)
{
    rpg->settings.button[4].rect = sfRectangleShape_create();
    rpg->settings.button[4].color.color = sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[4].color.hover_color = sfColor_fromRGBA(0, 0, 0, 25);
    sfRectangleShape_setPosition(rpg->settings.button[4].rect,
        (sfVector2f){1255, 527});
    sfRectangleShape_setSize(rpg->settings.button[4].rect,
        (sfVector2f){100, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[4].rect,
        rpg->settings.button[4].color.color);
    rpg->settings.button[4].is_clicked = &is_clicked;
    rpg->settings.button[4].is_hover = &is_hovered;
    rpg->settings.button[4].state = RELEASED;
}

void init_sfx_off_button(rpg_t *rpg)
{
    sfx_off_button_txt(rpg);
    sfx_off_button(rpg);
}

void sfx_off_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[4].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[6].text, NULL);
}
