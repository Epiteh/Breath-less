/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** save
*/

#include "rpg.h"

static void save_button_txt(rpg_t *rpg)
{
    rpg->save.txt[1].text = sfText_create();
    sfText_setString(rpg->save.txt[1].text, "Save");
    rpg->save.txt[1].font = sfFont_createFromFile("assets/Roboto-Light.ttf");
    sfText_setFont(rpg->save.txt[1].text, rpg->save.txt[1].font);
    sfText_setCharacterSize(rpg->save.txt[1].text, 35);
    sfText_setPosition(rpg->save.txt[1].text, (sfVector2f){920, 600});
    sfText_setColor(rpg->save.txt[1].text, sfBlack);
}

static void save_button(rpg_t *rpg)
{
    rpg->save.button[0].rect = sfRectangleShape_create();
    rpg->save.button[0].color.color = sfColor_fromRGBA(0, 0, 0, 0);
    rpg->save.button[0].color.hover_color = sfColor_fromRGBA(0, 0, 0, 25);
    rpg->save.button[0].color.pressed_color = sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->save.button[0].rect,
        (sfVector2f){902, 600});
    sfRectangleShape_setSize(rpg->save.button[0].rect,
        (sfVector2f){120, 50});
    sfRectangleShape_setFillColor(rpg->save.button[0].rect,
        rpg->save.button[0].color.color);
    rpg->save.button[0].is_clicked = &is_clicked;
    rpg->save.button[0].is_hover = &is_hovered;
    rpg->save.button[0].state = RELEASED;
}

void init_save_button(rpg_t *rpg)
{
    save_button_txt(rpg);
    save_button(rpg);
}

void save_button_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->save.button[0].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->save.txt[1].text, NULL);
}
