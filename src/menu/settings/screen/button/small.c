/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** small
*/

#include "rpg.h"

static void small_button_txt(rpg_t *rpg)
{
    rpg->settings.txt[3].text = sfText_create();
    sfText_setString(rpg->settings.txt[3].text, "800 x 600");
    sfText_setFont(rpg->settings.txt[3].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[3].text, 39);
    sfText_setPosition(rpg->settings.txt[3].text,
        (sfVector2f){1415, 428});
    sfText_setColor(rpg->settings.txt[3].text, sfBlack);
}

static void small_button(rpg_t *rpg)
{
    rpg->settings.button[2].rect = sfRectangleShape_create();
    rpg->settings.button[2].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[2].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->settings.button[2].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->settings.button[2].rect,
        (sfVector2f){1400, 424});
    sfRectangleShape_setSize(rpg->settings.button[2].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[2].rect,
        rpg->settings.button[2].color.color);
    rpg->settings.button[2].is_clicked = &is_clicked;
    rpg->settings.button[2].is_hover = &is_hovered;
    rpg->settings.button[2].state = RELEASED;
}

void init_small_button(rpg_t *rpg)
{
    small_button_txt(rpg);
    small_button(rpg);
}

void small_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[2].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[3].text, NULL);
}
