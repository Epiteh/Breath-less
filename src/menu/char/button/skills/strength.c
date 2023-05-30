/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** strenght
*/

#include "rpg.h"

static void strenght_creator_button_set_rect(rpg_t *rpg,
    unsigned int i, int pos, sfVector2f *pos_button)
{
    sfRectangleShape_setPosition(rpg->creator.button[i].rect,
        *pos_button);
    sfRectangleShape_setSize(rpg->creator.button[i].rect,
        (sfVector2f){25, 25});
    sfRectangleShape_setFillColor(rpg->creator.button[i].rect,
        rpg->creator.button[i].color.color);
    sfRectangleShape_setOutlineThickness(rpg->creator.button[i].rect, 2);
    sfRectangleShape_setOutlineColor(rpg->creator.button[i].rect,
        sfColor_fromRGBA(0, 0, 0, 255));
    rpg->creator.button[i].is_clicked = &is_clicked;
    rpg->creator.button[i].is_hover = &is_hovered;
    rpg->creator.button[i].state = RELEASED;
    pos_button->x += pos;
}

void strength_creator_button(rpg_t *rpg)
{
    unsigned int i;
    unsigned int pos = 51;
    sfVector2f pos_button = {1418, 495};

    for (i = 5; i < 10; i += 1) {
        rpg->creator.button[i].rect = sfRectangleShape_create();
        rpg->creator.button[i].color.color =
            sfColor_fromRGBA(0, 0, 0, 0);
        rpg->creator.button[i].color.hover_color =
            sfColor_fromRGBA(0, 0, 0, 25);
        rpg->creator.button[i].color.pressed_color =
            sfColor_fromRGBA(0, 0, 0, 50);
        strenght_creator_button_set_rect(rpg, i, pos, &pos_button);
    }
}

void display_strength_button(rpg_t *rpg)
{
    unsigned int i;

    for (i = 5; i < 10; i += 1) {
        sfRenderWindow_drawRectangleShape(rpg->window.window,
            rpg->creator.button[i].rect, NULL);
    }
}
