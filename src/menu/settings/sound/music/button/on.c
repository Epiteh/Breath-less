/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sfx
*/

#include "rpg.h"

static void music_on_button_txt(rpg_t *rpg)
{
    rpg->settings.txt[7].text = sfText_create();
    sfText_setString(rpg->settings.txt[7].text, "On");
    sfText_setFont(rpg->settings.txt[7].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[7].text, 39);
    sfText_setPosition(rpg->settings.txt[7].text, (sfVector2f){1125, 597});
    sfText_setColor(rpg->settings.txt[7].text, sfBlack);
}

static void music_on_button(rpg_t *rpg)
{
    rpg->settings.button[5].rect = sfRectangleShape_create();
    rpg->settings.button[5].color.color = sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[5].color.hover_color = sfColor_fromRGBA(0, 0, 0, 25);
    sfRectangleShape_setPosition(rpg->settings.button[5].rect,
        (sfVector2f){1100, 591});
    sfRectangleShape_setSize(rpg->settings.button[5].rect,
        (sfVector2f){100, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[5].rect,
        rpg->settings.button[5].color.color);
    rpg->settings.button[5].is_clicked = &is_clicked;
    rpg->settings.button[5].is_hover = &is_hovered;
    rpg->settings.button[5].state = RELEASED;
}

void init_music_on_button(rpg_t *rpg)
{
    music_on_button_txt(rpg);
    music_on_button(rpg);
}

void music_on_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[5].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[7].text, NULL);
}
