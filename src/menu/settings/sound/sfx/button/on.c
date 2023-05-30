/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sfx
*/

#include "rpg.h"

static void sfx_on_button_txt(rpg_t *rpg)
{
    rpg->settings.txt[5].text = sfText_create();
    sfText_setString(rpg->settings.txt[5].text, "On");
    sfText_setFont(rpg->settings.txt[5].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[5].text, 39);
    sfText_setPosition(rpg->settings.txt[5].text, (sfVector2f){1125, 533});
    sfText_setColor(rpg->settings.txt[5].text, sfBlack);
}

static void sfx_on_button(rpg_t *rpg)
{
    rpg->settings.button[3].rect = sfRectangleShape_create();
    rpg->settings.button[3].color.color = sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[3].color.hover_color = sfColor_fromRGBA(0, 0, 0, 25);
    sfRectangleShape_setPosition(rpg->settings.button[3].rect,
        (sfVector2f){1100, 527});
    sfRectangleShape_setSize(rpg->settings.button[3].rect,
        (sfVector2f){100, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[3].rect,
        rpg->settings.button[3].color.color);
    rpg->settings.button[3].is_clicked = &is_clicked;
    rpg->settings.button[3].is_hover = &is_hovered;
    rpg->settings.button[3].state = RELEASED;
}

void init_sfx_on_button(rpg_t *rpg)
{
    sfx_on_button_txt(rpg);
    sfx_on_button(rpg);
}

void sfx_on_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[3].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[5].text, NULL);
}
