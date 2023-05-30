/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** key
*/

#include "rpg.h"

static void interaction_key_button_txt(rpg_t *rpg)
{
    rpg->settings.interaction_key = 101 - 32;
    char *str = my_calloc(2, sizeof(char));
    str[0] = rpg->settings.interaction_key;

    rpg->settings.txt[9].text = sfText_create();
    sfText_setString(rpg->settings.txt[9].text, str);
    sfText_setFont(rpg->settings.txt[9].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[9].text, 39);
    sfText_setPosition(rpg->settings.txt[9].text, (sfVector2f){1125, 763});
    sfText_setColor(rpg->settings.txt[9].text, sfBlack);
}

static void interaction_key_button(rpg_t *rpg)
{
    rpg->settings.button[7].rect = sfRectangleShape_create();
    rpg->settings.button[7].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->settings.button[7].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->settings.button[7].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->settings.button[7].rect,
        (sfVector2f){1090, 758});
    sfRectangleShape_setSize(rpg->settings.button[7].rect,
        (sfVector2f){100, 60});
    sfRectangleShape_setFillColor(rpg->settings.button[7].rect,
        rpg->settings.button[7].color.color);
    rpg->settings.button[7].is_clicked = &is_clicked;
    rpg->settings.button[7].is_hover = &is_hovered;
    rpg->settings.button[7].state = RELEASED;
}

void init_interaction_key_button(rpg_t *rpg)
{
    interaction_key_button_txt(rpg);
    interaction_key_button(rpg);
}

void interaction_key_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->settings.button[7].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[9].text, NULL);
}
